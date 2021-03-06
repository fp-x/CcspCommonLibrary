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

    module:	dslh_snmpo_exported_api.h

        For DSL Home Model Implementation (DSLH),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc.
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Dslh Snmp Manager
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Bin Zhu

    ---------------------------------------------------------------

    revision:

        07/24/08    initial revision.

**********************************************************************/


#ifndef  _DSLH_SNMPO_EXPORTED_API_
#define  _DSLH_SNMPO_EXPORTED_API_


/***********************************************************
      FUNCTIONS IMPLEMENTED IN DSLH_SNMPO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
DslhCreateDslhSnmpManager
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
         FUNCTIONS IMPLEMENTED IN DSLH_SNMPO_BASE.C
***********************************************************/

ANSC_HANDLE
DslhSnmpoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
DslhSnmpoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhSnmpoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhSnmpoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
