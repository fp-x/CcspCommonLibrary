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

    module:	dslh_objco_exported_api.h

        For DSL Home Model Implementation (DSLH),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco System  , Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Dslh Obj Controller
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        09/23/05    initial revision.

**********************************************************************/


#ifndef  _DSLH_OBJCO_EXPORTED_API_
#define  _DSLH_OBJCO_EXPORTED_API_


/***********************************************************
       FUNCTIONS IMPLEMENTED IN DSLH_OBJCO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
DslhCreateObjController
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
          FUNCTIONS IMPLEMENTED IN DSLH_OBJCO_BASE.C
***********************************************************/

ANSC_HANDLE
DslhObjcoCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
DslhObjcoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhObjcoEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhObjcoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


/***********************************************************
         FUNCTIONS IMPLEMENTED IN DSLH_OBJCO_BASE.C
***********************************************************/

ANSC_HANDLE
DslhObjcoGetInsContext
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhObjcoSetInsContext
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInsContext
    );

ANSC_HANDLE
DslhObjcoGetParentInsContext
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
DslhObjcoSetParentInsContext
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInsContext
    );

ANSC_STATUS
DslhObjcoReset
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
