/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

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

    module:	ansc_dsuo_base.c

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the basic container object functions
        of the Ansc Daemon Server Udp Object.

        *   AnscDsuoCreate
        *   AnscDsuoRemove
        *   AnscDsuoEnrollObjects
        *   AnscDsuoInitialize

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        12/10/01    initial revision.

**********************************************************************/


#include "ansc_dsuo_global.h"


/**********************************************************************

    caller:     owner of the object

    prototype:

        ANSC_HANDLE
        AnscDsuoCreate
            (
                ANSC_HANDLE                 hContainerContext,
                ANSC_HANDLE                 hOwnerContext,
                ANSC_HANDLE                 hAnscReserved
            );

    description:

        This function constructs the Ansc Daemon Server Udp Object and
        initializes the member variables and functions.

    argument:   ANSC_HANDLE                 hContainerContext
                This handle is used by the container object to interact
                with the outside world. It could be the real container
                or an target object.

                ANSC_HANDLE                 hOwnerContext
                This handle is passed in by the owner of this object.

                ANSC_HANDLE                 hAnscReserved
                This handle is passed in by the owner of this object.

    return:     newly created container object.

**********************************************************************/

ANSC_HANDLE
AnscDsuoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_COMPONENT_OBJECT          pBaseObject  = NULL;
    PANSC_DAEMON_SERVER_UDP_OBJECT  pMyObject    = NULL;

    /*
     * We create object by first allocating memory for holding the variables and member functions.
     */
    pMyObject = (PANSC_DAEMON_SERVER_UDP_OBJECT)AnscAllocateMemory(sizeof(ANSC_DAEMON_SERVER_UDP_OBJECT));

    if ( !pMyObject )
    {
        return  (ANSC_HANDLE)NULL;
    }
    else
    {
        pBaseObject = (PANSC_COMPONENT_OBJECT)pMyObject;
    }

    /*
     * Initialize the common variables and functions for a container object.
     */
    AnscCopyString(pBaseObject->Name, ANSC_DAEMON_SERVER_UDP_NAME);

    pBaseObject->hContainerContext = hContainerContext;
    pBaseObject->hOwnerContext     = hOwnerContext;
    pBaseObject->Oid               = ANSC_DAEMON_SERVER_UDP_OID;
    pBaseObject->Create            = AnscDsuoCreate;
    pBaseObject->Remove            = AnscDsuoRemove;
    pBaseObject->EnrollObjects     = AnscDsuoEnrollObjects;
    pBaseObject->Initialize        = AnscDsuoInitialize;

    pBaseObject->EnrollObjects((ANSC_HANDLE)pBaseObject);
    pBaseObject->Initialize   ((ANSC_HANDLE)pBaseObject);

    return  (ANSC_HANDLE)pMyObject;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscDsuoRemove
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function destroys the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscDsuoRemove
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_DAEMON_SERVER_UDP_OBJECT  pMyObject    = (PANSC_DAEMON_SERVER_UDP_OBJECT)hThisObject;
    PANSC_DSUO_WORKER_OBJECT        pWorker      = (PANSC_DSUO_WORKER_OBJECT      )pMyObject->hWorker;

    pMyObject->Cancel((ANSC_HANDLE)pMyObject);
    pMyObject->Reset ((ANSC_HANDLE)pMyObject);

    AnscFreeEvent(&pMyObject->AcceptEvent    );
    AnscFreeLock (&pMyObject->OpLock         );
    AnscFreeLock (&pMyObject->EngineArrayLock);
    AnscFreeLock (&pMyObject->SocketSListLock);
    AnscFreeLock (&pMyObject->PacketSListLock);

    if ( pWorker )
    {
        AnscFreeMemory(pWorker);

        pMyObject->hWorker = (ANSC_HANDLE)NULL;
    }

    AnscCoRemove((ANSC_HANDLE)pMyObject);

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscDsuoEnrollObjects
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function enrolls all the objects required by this object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscDsuoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_DAEMON_SERVER_UDP_OBJECT  pMyObject    = (PANSC_DAEMON_SERVER_UDP_OBJECT)hThisObject;

    AnscCoEnrollObjects((ANSC_HANDLE)pMyObject);

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscDsuoInitialize
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function first calls the initialization member function
        of the base class object to set the common member fields
        inherited from the base class. It then initializes the member
        fields that are specific to this object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscDsuoInitialize
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_DAEMON_SERVER_UDP_OBJECT  pMyObject    = (PANSC_DAEMON_SERVER_UDP_OBJECT)hThisObject;

    /*
     * Until you have to simulate C++ object-oriented programming style with standard C, you don't
     * appreciate all the nice little things come with C++ language and all the dirty works that
     * have been done by the C++ compilers. Member initialization is one of these things. While in
     * C++ you don't have to initialize all the member fields inherited from the base class since
     * the compiler will do it for you, such is not the case with C.
     */
    AnscCoInitialize((ANSC_HANDLE)pMyObject);

    /*
     * Although we have initialized some of the member fields in the "create" member function, we
     * repeat the work here for completeness. While this simulation approach is pretty stupid from
     * a C++/Java programmer perspective, it's the best we can get for universal embedded network
     * programming. Before we develop our own operating system (don't expect that to happen any
     * time soon), this is the way things gonna be.
     */
    pMyObject->Oid                   = ANSC_DAEMON_SERVER_UDP_OID;
    pMyObject->Create                = AnscDsuoCreate;
    pMyObject->Remove                = AnscDsuoRemove;
    pMyObject->EnrollObjects         = AnscDsuoEnrollObjects;
    pMyObject->Initialize            = AnscDsuoInitialize;

    pMyObject->Socket                = ANSC_SOCKET_INVALID_SOCKET;
    pMyObject->hWorker               = (ANSC_HANDLE)NULL;
    pMyObject->MaxMessageSize        = ANSC_DSUO_MAX_MESSAGE_SIZE;
    pMyObject->EngineCount           = ANSC_DSUO_DEF_ENGINE_COUNT;
    pMyObject->hNextEngineToUse      = (ANSC_HANDLE)NULL;
    pMyObject->CurSocketCount        = 0;
    pMyObject->MinSocketCount        = ANSC_DSUO_MIN_SOCKET_COUNT;
    pMyObject->MaxSocketCount        = ANSC_DSUO_MAX_SOCKET_COUNT;
    pMyObject->CurPacketCount        = 0;
    pMyObject->MinPacketCount        = ANSC_DSUO_MIN_PACKET_COUNT;
    pMyObject->MaxPacketCount        = ANSC_DSUO_MAX_PACKET_COUNT;
    pMyObject->SocketTimeOut         = ANSC_DSUO_SOCKET_TIMEOUT;
    pMyObject->PacketTimeOut         = ANSC_DSUO_PACKET_TIMEOUT;
    pMyObject->Mode                  = 0;
    pMyObject->bActive               = FALSE;

    pMyObject->GetHostAddress        = AnscDsuoGetHostAddress;
    pMyObject->SetHostAddress        = AnscDsuoSetHostAddress;
    pMyObject->GetHostPort           = AnscDsuoGetHostPort;
    pMyObject->SetHostPort           = AnscDsuoSetHostPort;

    pMyObject->GetWorker             = AnscDsuoGetWorker;
    pMyObject->SetWorker             = AnscDsuoSetWorker;
    pMyObject->GetMaxMessageSize     = AnscDsuoGetMaxMessageSize;
    pMyObject->SetMaxMessageSize     = AnscDsuoSetMaxMessageSize;
    pMyObject->GetEngineCount        = AnscDsuoGetEngineCount;
    pMyObject->SetEngineCount        = AnscDsuoSetEngineCount;
    pMyObject->GetMinSocketCount     = AnscDsuoGetMinSocketCount;
    pMyObject->SetMinSocketCount     = AnscDsuoSetMinSocketCount;
    pMyObject->GetMaxSocketCount     = AnscDsuoGetMaxSocketCount;
    pMyObject->SetMaxSocketCount     = AnscDsuoSetMaxSocketCount;
    pMyObject->GetMinPacketCount     = AnscDsuoGetMinPacketCount;
    pMyObject->SetMinPacketCount     = AnscDsuoSetMinPacketCount;
    pMyObject->GetMaxPacketCount     = AnscDsuoGetMaxPacketCount;
    pMyObject->SetMaxPacketCount     = AnscDsuoSetMaxPacketCount;
    pMyObject->GetSocketTimeOut      = AnscDsuoGetSocketTimeOut;
    pMyObject->SetSocketTimeOut      = AnscDsuoSetSocketTimeOut;
    pMyObject->GetPacketTimeOut      = AnscDsuoGetPacketTimeOut;
    pMyObject->SetPacketTimeOut      = AnscDsuoSetPacketTimeOut;
    pMyObject->GetMode               = AnscDsuoGetMode;
    pMyObject->SetMode               = AnscDsuoSetMode;
    pMyObject->Reset                 = AnscDsuoReset;

    pMyObject->AcceptTask            = AnscDsuoAcceptTask;
    pMyObject->WorkerTask            = AnscDsuoWorkerTask;

    pMyObject->Engage                = AnscDsuoEngage;
    pMyObject->Cancel                = AnscDsuoCancel;

    pMyObject->StartEngines          = AnscDsuoStartEngines;
    pMyObject->StopEngines           = AnscDsuoStopEngines;

    pMyObject->AcquireSocket         = AnscDsuoAcquireSocket;
    pMyObject->ReleaseSocket         = AnscDsuoReleaseSocket;
    pMyObject->ManufactureSocketPool = AnscDsuoManufactureSocketPool;
    pMyObject->DestroySocketPool     = AnscDsuoDestroySocketPool;

    pMyObject->AcquirePacket         = AnscDsuoAcquirePacket;
    pMyObject->ReleasePacket         = AnscDsuoReleasePacket;
    pMyObject->ManufacturePacketPool = AnscDsuoManufacturePacketPool;
    pMyObject->DestroyPacketPool     = AnscDsuoDestroyPacketPool;

    pMyObject->AssignEngine          = AnscDsuoAssignEngine;
    pMyObject->ManufactureEnginePool = AnscDsuoManufactureEnginePool;
    pMyObject->DestroyEnginePool     = AnscDsuoDestroyEnginePool;

    pMyObject->Query                 = AnscDsuoQuery;
    pMyObject->ProcessSync           = AnscDsuoProcessSync;
    pMyObject->ProcessAsync          = AnscDsuoProcessAsync;

    AnscInitializeLock       (&pMyObject->OpLock     );
    AnscInitializeEvent      (&pMyObject->AcceptEvent);
    AnscSetEvent             (&pMyObject->AcceptEvent);

    AnscInitializeLock       (&pMyObject->EngineArrayLock);
    AnscSListInitializeHeader(&pMyObject->SocketSList    );
    AnscInitializeLock       (&pMyObject->SocketSListLock);
    AnscSListInitializeHeader(&pMyObject->PacketSList    );
    AnscInitializeLock       (&pMyObject->PacketSListLock);

    return  ANSC_STATUS_SUCCESS;
}
