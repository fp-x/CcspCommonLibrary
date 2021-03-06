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

    module:	ansc_co_external_api.h

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the container.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        06/07/01    initial revision.

**********************************************************************/


#ifndef  _ANSC_CO_EXTERNAL_API_
#define  _ANSC_CO_EXTERNAL_API_


/***********************************************************
           FUNCTIONS IMPLEMENTED IN ANSC_CO_BASE.C
***********************************************************/

ANSC_HANDLE
AnscCoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
AnscCoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscCoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscCoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );

/*
ANSC_HANDLE
AnscCoGetOwner
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscCoSetOwner
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hOwner
    );

char*
AnscCoGetName
    (
        ANSC_HANDLE                 hThisObject
    );

ULONG
AnscCoGetOid
    (
        ANSC_HANDLE                 hThisObject
    );

ULONG
AnscCoGetRid
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscCoDispatchEvent
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hEvent
    );
*/


#endif
