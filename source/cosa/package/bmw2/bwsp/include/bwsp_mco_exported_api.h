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

    module:	bwsp_mco_exported_api.h

        For Broadway Web Service Plane Implementation (BWSP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Bwsp Module
        Container Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        08/02/03    initial revision.

**********************************************************************/


#ifndef  _BWSP_MCO_EXPORTED_API_
#define  _BWSP_MCO_EXPORTED_API_


/***********************************************************
        FUNCTIONS IMPLEMENTED IN BWSP_MCO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
BwspCreateModuleContainer
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
           FUNCTIONS IMPLEMENTED IN BWSP_MCO_BASE.C
***********************************************************/

ANSC_HANDLE
BwspMcoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
BwspMcoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
BwspMcoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
BwspMcoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
