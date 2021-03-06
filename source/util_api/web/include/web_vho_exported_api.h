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

    module:	web_vho_exported_api.h

        For Web Server/Client/Application Implementation (WEB),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Web Virtual Host
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        03/09/02    initial revision.

**********************************************************************/


#ifndef  _WEB_VHO_EXPORTED_API_
#define  _WEB_VHO_EXPORTED_API_


/***********************************************************
         FUNCTIONS IMPLEMENTED IN WEB_VHO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
WebCreateVirtualHost
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
           FUNCTIONS IMPLEMENTED IN WEB_VHO_BASE.C
***********************************************************/

ANSC_HANDLE
WebVhoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
WebVhoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
WebVhoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
WebVhoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


/***********************************************************
           FUNCTIONS IMPLEMENTED IN WEB_VHO_STATES.C
***********************************************************/

ANSC_STATUS
WebVhoResetProperty
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
WebVhoReset
    (
        ANSC_HANDLE                 hThisObject
    );


/***********************************************************
        FUNCTIONS IMPLEMENTED IN WEB_VHO_OPERATION.C
***********************************************************/

ANSC_STATUS
WebVhoEngage
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
WebVhoCancel
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
