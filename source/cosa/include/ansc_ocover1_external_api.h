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

    module:	ansc_ocover1_external_api.h

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco System  , Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the external functions provided by the Ansc OcoVer1 Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        12/07/01    initial revision.

**********************************************************************/


#ifndef  _ANSC_OCOVER1_EXTERNAL_API_
#define  _ANSC_OCOVER1_EXTERNAL_API_


/***********************************************************
     FUNCTIONS IMPLEMENTED IN ANSC_OCOVER1_INTERFACE.C
***********************************************************/

ANSC_HANDLE
AnscCreateOcoVer1
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
         FUNCTIONS IMPLEMENTED IN ANSC_OCOVER1_BASE.C
***********************************************************/

ANSC_HANDLE
AnscOcoVer1Create
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
AnscOcoVer1Remove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscOcoVer1EnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscOcoVer1Initialize
    (
        ANSC_HANDLE                 hThisObject
    );


/***********************************************************
      FUNCTIONS IMPLEMENTED IN ANSC_OCOVER1_OPERATION.C
***********************************************************/

ANSC_STATUS
AnscOcoVer1Engage
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscOcoVer1Cancel
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscOcoVer1SubEngage
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscOcoVer1SubCancel
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
