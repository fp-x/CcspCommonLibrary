/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/


/**********************************************************************

    module:	scli_shell_process.c

        For Simple CLI Shell object (SCLISH),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved

    ---------------------------------------------------------------

    description:

        This module implements the interface functions
        of the SCLI Shell Object.

        *   ScliShoAsyncRunCmdTask
             
    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Kang Quan

    ---------------------------------------------------------------

    revision:

        06/15/05    initial revision.

**********************************************************************/


#include "scli_shell_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        ScliShoAsyncRunCmdTask
            (
                ANSC_HANDLE                 hContext
            );

    description:

        This function is called to run non built-in commands.

    argument:   ANSC_HANDLE                 hContet
                Context.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
ScliShoAsyncRunCmdTask
    (
        ANSC_HANDLE                 hContext
    )
{
    ANSC_STATUS                     returnStatus    = ANSC_STATUS_SUCCESS;
    PSCLI_SHELL_ASYNC_TASK_CONTEXT  pContext        = (PSCLI_SHELL_ASYNC_TASK_CONTEXT)hContext;
    PSCLI_SHELL_OBJECT              pMyObject       = (PSCLI_SHELL_OBJECT            )pContext->hScliShell;
    PSCLI_SHELL_PROPERTY            pProperty       = (PSCLI_SHELL_PROPERTY          )&pMyObject->Property;
    PTELNET_CMD_EXECUTION_ENV       pExecEnv        = &pContext->ExecEnv;
    PTELNET_TSC_INTERFACE           pTscIf          = (PTELNET_TSC_INTERFACE         )pExecEnv->hTscIf;
    ANSC_HANDLE                     hSrvSession     = pContext->hSrvSession;
    PUCHAR                          pCmd            = pContext->pCmd;
    PSCLI_SHELL_CEN_INTERFACE       pCenIf          = (PSCLI_SHELL_CEN_INTERFACE     )pMyObject->hCenIf;
    PBMC2_SCC_INTERFACE             pBmc2SccIf      = (PBMC2_SCC_INTERFACE           )pMyObject->hBmc2SccIf;
    PBMC2_ICE_INTERFACE             pBmc2IceIf      = NULL;
    PSCLI_SHELL_SESSION_EXEC        pSession;
    BMC2_COMMAND_REPLY              CmdReply        = { 0 };
    BMC2_COMMAND_REQUEST            CmdRequest      = { 0 };

    pSession    = (PSCLI_SHELL_SESSION_EXEC)pMyObject->GetSession((ANSC_HANDLE)pMyObject, (ULONG)hSrvSession);

    if ( pMyObject->hBmc2SccIf )
    {
        int                         nRow = -1, nCol = -1;
        ULONG                       ulInputMode;

        pBmc2IceIf      = (PBMC2_ICE_INTERFACE)pSession->hBmc2IceIf;        

        CmdRequest.CommandLine  = pCmd;

        if ( returnStatus == ANSC_STATUS_SUCCESS )
        {
            ulInputMode = 
                pMyObject->GetInputMode
                    (
                        (ANSC_HANDLE)pMyObject,
                        hSrvSession
                    );

            CmdRequest.CurLineNumber    = nRow - 1;

            if ( ulInputMode == SCLI_SHELL_INPUT_MODE_linemode && nRow > 0 )
            {
                CmdRequest.CurLineNumber --;
            }
        }

        returnStatus = 
            pBmc2SccIf->ExecuteCommand
                (
                    pBmc2SccIf->hOwnerContext,
                    pSession->hBmc2Terminal,
                    (ANSC_HANDLE)&CmdRequest,
                    (ANSC_HANDLE)&CmdReply
                );
    }

    pSession->InputMode = SCLI_SHELL_INPUT_MODE_linemode;

    if ( CmdReply.ErrorCode != 0 )
    {
        UCHAR                       errMsg[64];

        _ansc_sprintf
            (
                errMsg,
                SCLI_SHELL_INTERNAL_ERROR,
                CmdReply.ErrorCode
            );

        pTscIf->Output
            (
                pTscIf->hOwnerContext,
                hSrvSession,
                errMsg,
                AnscSizeOfString(errMsg)
            );
    }

    switch ( CmdReply.StateCode )
    {
        case    BMC2_TERMINAL_STATE_enterSubMenu:
        case    BMC2_TERMINAL_STATE_leaveSubMenu:
        case    BMC2_TERMINAL_STATE_exitToRoot:

                pMyObject->ShellPromptChanged
                    (
                        (ANSC_HANDLE)pMyObject,
                        hSrvSession,
                        (ANSC_HANDLE)pExecEnv,
                        CmdReply.MenuTitle
                    );

                break;

        case    BMC2_TERMINAL_STATE_exitTerminal:

                /*
                returnStatus = 
                    pMyObject->RunBuiltInCmd
                        (
                            (ANSC_HANDLE)pMyObject,
                            hSrvSession,
                            (ANSC_HANDLE)pExecEnv,
                            SCLI_SHELL_BICODE_Exit
                        );
                */

                pSession->bWillExit = TRUE;

                break;
    }

    if ( CmdReply.MenuTitle )
    {
        AnscFreeMemory(CmdReply.MenuTitle);
    }

    pCenIf->Notify
        (
            pCenIf->hOwnerContext,
            pSession->hCeeExecEnv,
            SCLI_SHELL_CEN_EVENT_CmdEnd
        );

    if ( pContext->pCmd )
    {
        AnscFreeMemory(pContext->pCmd);
    }

    AnscFreeMemory(pContext);

    return returnStatus;
}

