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

    module:	http_bmoreq_rcp.c

        For HyperText Transfer Protocol Implementation (HTTP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced rcp-interface functions
        of the Http Bmo Req Object.

        *   HttpBmoReqRcpGetDocumentRoot
        *   HttpBmoReqRcpGetPathInfo
        *   HttpBmoReqRcpGetPathTranslated
        *   HttpBmoReqRcpGetRemoteUser
        *   HttpBmoReqRcpGetScriptName
        *   HttpBmoReqRcpGetServerName
        *   HttpBmoReqRcpGetServerPort
        *   HttpBmoReqRcpGetServerProtocol
        *   HttpBmoReqRcpGetServerSoftware

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        03/15/02    initial revision.

**********************************************************************/


#include "http_bmoreq_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetDocumentRoot
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetDocumentRoot
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    return  HTTP_ROOT_URI_PATH;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetPathInfo
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetPathInfo
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;
    PHTTP_REQUEST_INFO              pReqInfo     = (PHTTP_REQUEST_INFO           )pMyObject->hReqInfo;
    char*                           pPathInfo    = (char*                        )pMyObject->RcpMpad;
    ULONG                           ulPathLen    = 0;
    ULONG                           i            = 0;

    for ( i = 0; i < pReqInfo->RequestUri.PathLevel; i++ )
    {
        AnscCopyString((char*)(pPathInfo + ulPathLen), pReqInfo->RequestUri.PathArray[i]);

        ulPathLen += AnscSizeOfString(pReqInfo->RequestUri.PathArray[i]);

        if ( pPathInfo[ulPathLen - 1] != '/' )
        {
            pPathInfo[ulPathLen++] = '/';
        }
    }

    if ( ulPathLen > 1 )
    {
        pPathInfo[--ulPathLen] = 0;
    }

    return  pPathInfo;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetPathTranslated
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetPathTranslated
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;
    PHTTP_REQUEST_INFO              pReqInfo     = (PHTTP_REQUEST_INFO           )pMyObject->hReqInfo;
    char*                           pPathInfo    = (char*                        )pMyObject->RcpBpad;
    ULONG                           ulPathLen    = 0;
    ULONG                           i            = 0;

    for ( i = 0; i < pReqInfo->RequestUri.PathLevel; i++ )
    {
        AnscCopyString((char*)(pPathInfo + ulPathLen), pReqInfo->RequestUri.PathArray[i]);

        ulPathLen             += AnscSizeOfString(pReqInfo->RequestUri.PathArray[i]);
        pPathInfo[ulPathLen++] = '/';
    }

    if ( ulPathLen > 1 )
    {
        pPathInfo[--ulPathLen] = 0;
    }

    return  pPathInfo;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetRemoteUser
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetRemoteUser
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    return  NULL;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetScriptName
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetScriptName
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    return  NULL;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetServerName
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetServerName
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    return  pMyObject->GetServerName((ANSC_HANDLE)pMyObject);
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        USHORT
        HttpBmoReqRcpGetServerPort
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

USHORT
HttpBmoReqRcpGetServerPort
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    /*return  pMyObject->GetServerPort((ANSC_HANDLE)pMyObject);*/
    return  pMyObject->GetDaemonPort((ANSC_HANDLE)pMyObject);
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetServerProtocol
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetServerProtocol
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    return  HTTP_CURRENT_VERSION;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        char*
        HttpBmoReqRcpGetServerSoftware
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hBmoReq
            );

    description:

        This function is called to retrieve CGI environment variable.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hBmoReq
                Specifies the associated request message object.

    return:     CGI environment variable.

**********************************************************************/

char*
HttpBmoReqRcpGetServerSoftware
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hBmoReq
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_BMO_REQ_OBJECT            pMyObject    = (PHTTP_BMO_REQ_OBJECT         )hThisObject;

    return  HTTP_SERVER_PRODUCT_NAME;
}
