/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

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

    module:	slap_bmc2domo_internal_api.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the internal functions provided by the Slap Bmc2 Domain
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        06/29/05    initial revision.

**********************************************************************/


#ifndef  _SLAP_BMC2DOMO_INTERNAL_API_
#define  _SLAP_BMC2DOMO_INTERNAL_API_


/***********************************************************
       FUNCTIONS IMPLEMENTED IN SLAP_BMC2DOMO_STATES.C
***********************************************************/

ANSC_HANDLE
SlapBmc2DomoGetSlapGoaIf
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_HANDLE
SlapBmc2DomoGetOlmContainer
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2DomoReset
    (
        ANSC_HANDLE                 hThisObject
    );


/***********************************************************
       FUNCTIONS IMPLEMENTED IN SLAP_BMC2DOMO_ACCESS.C
***********************************************************/

char*
SlapBmc2DomoGetDomainName
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2DomoAddCommand
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

ANSC_STATUS
SlapBmc2DomoSetCommandSyntax
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand,
        PSLAP_STRING_ARRAY          ReqArgs,  
        PSLAP_STRING_ARRAY          OptArgs
    );

ANSC_STATUS
SlapBmc2DomoSetCommandSyntaxString
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand,
        char*                       pReqArgsSyntax,
        char*                       pOptArgsSyntax
    );

ANSC_STATUS
SlapBmc2DomoDelCommand
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

ANSC_STATUS
SlapBmc2DomoEnableCommand
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand,
        BOOL                        bEnable
    );

SLAP_BOOL
SlapBmc2DomoIsCommandValid
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

SLAP_BOOL
SlapBmc2DomoIsCommandAuthorized
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

ANSC_STATUS
SlapBmc2DomoExit
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SlapBmc2DomoExitToRoot
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
