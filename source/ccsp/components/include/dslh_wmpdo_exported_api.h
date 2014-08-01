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

    module:	dslh_wmpdo_exported_api.h

        For DSL Home Model Implementation (DSLH),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco System  , Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Dslh Wmp Database
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        09/06/05    initial revision.

**********************************************************************/


#ifndef  _DSLH_WMPDO_EXPORTED_API_
#define  _DSLH_WMPDO_EXPORTED_API_


/***********************************************************
       FUNCTIONS IMPLEMENTED IN DSLH_WMPDO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
DslhCreateWmpDatabase
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
          FUNCTIONS IMPLEMENTED IN DSLH_WMPDO_BASE.C
***********************************************************/

ANSC_HANDLE
DslhWmpdoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
DslhWmpdoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhWmpdoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhWmpdoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
