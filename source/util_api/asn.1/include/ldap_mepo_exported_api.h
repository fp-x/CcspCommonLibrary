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

    module: ldap_mepo_exported_api.h

        For Lightweight Directory Access Protocol (V3) (LDAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2006
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines all the platform-independent
        functions and macros for external access to the LDAP 
		Message Element Parser Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Arun Vijay Mani

    ---------------------------------------------------------------

    revision:

        12/28/05    initial revision.

**********************************************************************/


#ifndef  _LDAP_MEPO_EXPORTED_API_
#define  _LDAP_MEPO_EXPORTED_API_


/***********************************************************
        FUNCTIONS IMPLEMENTED IN LDAP_MEPO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
LdapCreateMepo
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
          FUNCTIONS IMPLEMENTED IN LDAP_MEPO_BASE.C
***********************************************************/

ANSC_HANDLE
LdapMepCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
LdapMepRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
LdapMepEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
LdapMepInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
