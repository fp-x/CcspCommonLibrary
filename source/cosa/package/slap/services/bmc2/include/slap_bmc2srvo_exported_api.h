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

    module:	slap_bmc2srvo_exported_api.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Slap Bmc2 Server
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        06/23/05    initial revision.

**********************************************************************/


#ifndef  _SLAP_BMC2SRVO_EXPORTED_API_
#define  _SLAP_BMC2SRVO_EXPORTED_API_


/***********************************************************
     FUNCTIONS IMPLEMENTED IN SLAP_BMC2SRVO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
SlapCreateBmc2Server
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_HANDLE
SlapBmc2SrvoGetSlapObjCallMap
    (
        ANSC_HANDLE                 hContainerContext
    );

ANSC_HANDLE
SlapBmc2SrvoGetSlapObjDescriptor
    (
        ANSC_HANDLE                 hContainerContext
    );


/***********************************************************
        FUNCTIONS IMPLEMENTED IN SLAP_BMC2SRVO_BASE.C
***********************************************************/

ANSC_HANDLE
SlapBmc2SrvoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
SlapBmc2SrvoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2SrvoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2SrvoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
