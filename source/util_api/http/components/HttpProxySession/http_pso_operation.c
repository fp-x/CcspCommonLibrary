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

    module:	http_pso_operation.c

        For HyperText Transfer Protocol Implementation (HTTP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced operation functions
        of the Http Proxy Session Object.

        *   HttpPsoOpen
        *   HttpPsoClose
        *   HttpPsoAcquireAccess
        *   HttpPsoReleaseAccess

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        02/22/02    initial revision.

**********************************************************************/


#include "http_pso_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        HttpPsoOpen
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to enable session activities.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
HttpPsoOpen
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_PROXY_SESSION_OBJECT      pMyObject    = (PHTTP_PROXY_SESSION_OBJECT)hThisObject;
    PHTTP_SIMPLE_PROXY_OBJECT       pSimpleProxy = (PHTTP_SIMPLE_PROXY_OBJECT )pMyObject->hOwnerContext;
    PHTTP_HFP_INTERFACE             pHfpIf       = (PHTTP_HFP_INTERFACE       )pMyObject->hHfpIf;
    PHTTP_TMH_INTERFACE             pTmhClientIf = (PHTTP_TMH_INTERFACE       )pMyObject->hTmhClientIf;
    PHTTP_TMH_INTERFACE             pTmhServerIf = (PHTTP_TMH_INTERFACE       )pMyObject->hTmhServerIf;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        HttpPsoClose
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to disable session activities.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
HttpPsoClose
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_PROXY_SESSION_OBJECT      pMyObject    = (PHTTP_PROXY_SESSION_OBJECT)hThisObject;
    PHTTP_SIMPLE_PROXY_OBJECT       pSimpleProxy = (PHTTP_SIMPLE_PROXY_OBJECT )pMyObject->hOwnerContext;

    pMyObject->DelAllBmoReqs((ANSC_HANDLE)pMyObject);
    pMyObject->DelAllBmoReps((ANSC_HANDLE)pMyObject);

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        HttpPsoAcquireAccess
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to acquire access to the session object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
HttpPsoAcquireAccess
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus   = ANSC_STATUS_SUCCESS;
    PHTTP_PROXY_SESSION_OBJECT      pMyObject      = (PHTTP_PROXY_SESSION_OBJECT)hThisObject;
    PHTTP_SIMPLE_PROXY_OBJECT       pSimpleProxy   = (PHTTP_SIMPLE_PROXY_OBJECT )pMyObject->hOwnerContext;

    AnscAcquireLock(&pMyObject->AccessLock);

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        HttpPsoReleaseAccess
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to release access to the session object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
HttpPsoReleaseAccess
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus   = ANSC_STATUS_SUCCESS;
    PHTTP_PROXY_SESSION_OBJECT      pMyObject      = (PHTTP_PROXY_SESSION_OBJECT)hThisObject;
    PHTTP_SIMPLE_PROXY_OBJECT       pSimpleProxy   = (PHTTP_SIMPLE_PROXY_OBJECT )pMyObject->hOwnerContext;

    AnscReleaseLock(&pMyObject->AccessLock);

    return  ANSC_STATUS_SUCCESS;
}
