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

    module:	ansc_string_array_co_exported_api.h

        For String Array Object,
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the String Array Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Kang Quan

    ---------------------------------------------------------------

    revision:

        03/26/02    initial revision.

    ---------------------------------------------------------------

    last modified:  
    

**********************************************************************/


#ifndef  _ANSC_STRING_ARRAY_CO_EXPORTED_API_
#define  _ANSC_STRING_ARRAY_CO_EXPORTED_API_


/***********************************************************
   FUNCTIONS IMPLEMENTED IN ansc_string_array_CO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
AnscCreateStringArrayComponent
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


ANSC_HANDLE
AnscStringArrayCOCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
AnscStringArrayCORemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscStringArrayCOEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscStringArrayCOInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
