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

    module:	slap_bmc2termo_exported_api.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Slap Bmc2 Terminal
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        06/24/05    initial revision.

**********************************************************************/


#ifndef  _SLAP_BMC2TERMO_EXPORTED_API_
#define  _SLAP_BMC2TERMO_EXPORTED_API_


/***********************************************************
     FUNCTIONS IMPLEMENTED IN SLAP_BMC2TERMO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
SlapCreateBmc2Terminal
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_HANDLE
SlapBmc2TermoGetSlapObjCallMap
    (
        ANSC_HANDLE                 hContainerContext
    );

ANSC_HANDLE
SlapBmc2TermoGetSlapObjDescriptor
    (
        ANSC_HANDLE                 hContainerContext
    );


/***********************************************************
       FUNCTIONS IMPLEMENTED IN SLAP_BMC2TERMO_BASE.C
***********************************************************/

ANSC_HANDLE
SlapBmc2TermoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
SlapBmc2TermoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2TermoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2TermoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
