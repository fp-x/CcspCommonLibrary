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

    module:	web_roo_operation.c

        For Web Server/Client/Application Implementation (WEB),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced operation functions
        of the Web Resource Owner Object.

        *   WebRooAcquireAccess
        *   WebRooReleaseAccess
        *   WebRooEngage
        *   WebRooCancel

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        03/13/02    initial revision.

**********************************************************************/


#include "web_roo_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        WebRooAcquireAccess
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to acquire the access to the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
WebRooAcquireAccess
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PWEB_RESOURCE_OWNER_OBJECT      pMyObject    = (PWEB_RESOURCE_OWNER_OBJECT  )hThisObject;
    PWEB_RESOURCE_OWNER_PROPERTY    pProperty    = (PWEB_RESOURCE_OWNER_PROPERTY)&pMyObject->Property;

    AnscAcquireLock(&pMyObject->SyncLock);

    return  returnStatus;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        WebRooReleaseAccess
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to release the access to the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
WebRooReleaseAccess
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PWEB_RESOURCE_OWNER_OBJECT      pMyObject    = (PWEB_RESOURCE_OWNER_OBJECT  )hThisObject;
    PWEB_RESOURCE_OWNER_PROPERTY    pProperty    = (PWEB_RESOURCE_OWNER_PROPERTY)&pMyObject->Property;

    AnscReleaseLock(&pMyObject->SyncLock);

    return  returnStatus;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        WebRooEngage
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to enage the object activity.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
WebRooEngage
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PWEB_RESOURCE_OWNER_OBJECT      pMyObject    = (PWEB_RESOURCE_OWNER_OBJECT  )hThisObject;
    PWEB_RESOURCE_OWNER_PROPERTY    pProperty    = (PWEB_RESOURCE_OWNER_PROPERTY)&pMyObject->Property;
    PWEB_AUTH_SERVER_OBJECT         pAuthServer  = (PWEB_AUTH_SERVER_OBJECT     )pMyObject->hAuthServer;
    BOOL                            bAuthEnabled = FALSE;

    if ( pMyObject->bActive )
    {
        return  ANSC_STATUS_SUCCESS;
    }
    else
    {
        pMyObject->bActive = TRUE;
    }

    if ( pProperty->AuthType == WEB_ROO_AUTH_TYPE_BASIC || pProperty->AuthType == WEB_ROO_AUTH_TYPE_DIGEST )
    {
        bAuthEnabled    = TRUE;
    }

    if ( bAuthEnabled )
    {
        if ( !pAuthServer )
        {
            pAuthServer = (PWEB_AUTH_SERVER_OBJECT)WebCreateAuthso(NULL, (ANSC_HANDLE)pMyObject, NULL);
            pMyObject->hAuthServer  = (ANSC_HANDLE)pAuthServer;
        }

        if ( pAuthServer )
        {
            PWEB_AUTH_SERVER_PROPERTY   pAuthProperty;

            pAuthProperty   = (PWEB_AUTH_SERVER_PROPERTY)AnscAllocateMemory(sizeof(WEB_AUTH_SERVER_PROPERTY));

            if ( pAuthProperty )
            {
                pAuthServer->GetProperty((ANSC_HANDLE)pAuthServer, (ANSC_HANDLE)pAuthProperty);

                pAuthProperty->AuthType = 
                    ( pProperty->AuthType == WEB_ROO_AUTH_TYPE_BASIC ) ? 
                        HTTP_AUTH_TYPE_BASIC : HTTP_AUTH_TYPE_DIGEST;

                if ( pProperty->RegPath[0] != '\0' )
                {
                    AnscCopyString(pAuthProperty->Domain, pProperty->RegPath);
                }

                pAuthServer->SetProperty((ANSC_HANDLE)pAuthServer, (ANSC_HANDLE)pAuthProperty);

                AnscFreeMemory(pAuthProperty);
            }
        }
    }
    else
    {
        if ( pAuthServer )
        {
            pMyObject->hAuthServer  = NULL;

            pAuthServer->Remove((ANSC_HANDLE)pAuthServer);
        }
    }

    return  returnStatus;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        WebRooCancel
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to cancel the object activity.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
WebRooCancel
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PWEB_RESOURCE_OWNER_OBJECT      pMyObject    = (PWEB_RESOURCE_OWNER_OBJECT  )hThisObject;
    PWEB_RESOURCE_OWNER_PROPERTY    pProperty    = (PWEB_RESOURCE_OWNER_PROPERTY)&pMyObject->Property;
    PWEB_AUTH_SERVER_OBJECT         pAuthServer  = (PWEB_AUTH_SERVER_OBJECT     )pMyObject->hAuthServer;

    if ( !pMyObject->bActive )
    {
        return  ANSC_STATUS_SUCCESS;
    }
    else
    {
        pMyObject->bActive = FALSE;

        if ( pAuthServer )
        {
            pAuthServer->Remove((ANSC_HANDLE)pAuthServer);
            pMyObject->hAuthServer  = (ANSC_HANDLE)NULL;
        }
    }

    return  returnStatus;
}


