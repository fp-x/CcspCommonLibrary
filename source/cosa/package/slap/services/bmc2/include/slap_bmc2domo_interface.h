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

    module:	slap_bmc2domo_interface.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines all the platform-independent
        functions and macros for the Slap Bmc2 Domain Object.

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


#ifndef  _SLAP_BMC2DOMO_INTERFACE_
#define  _SLAP_BMC2DOMO_INTERFACE_


/*
 * This object is derived a virtual base object defined by the underlying framework. We include the
 * interface header files of the base object here to shield other objects from knowing the derived
 * relationship between this object and its base class.
 */
#include "slap_scogal_interface.h"
#include "slap_scogal_exported_api.h"


/***********************************************************
        SLAP BMC2 DOMAIN COMPONENT OBJECT DEFINITION
***********************************************************/

/*
 * Define some const values that will be used in the object mapper object definition.
 */
#define  SLAP_BMC2DOMO_UOA_NAME                     "Services.Bmc2.Domain"

/*
 * Since we write all kernel modules in C (due to better performance and lack of compiler support),
 * we have to simulate the C++ object by encapsulating a set of functions inside a data structure.
 */
typedef  ANSC_HANDLE
(*PFN_BMC2DOMO_GET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_SET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hContext
    );

typedef  ANSC_HANDLE
(*PFN_BMC2DOMO_GET_IF)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_SET_IF)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    );

typedef  char*
(*PFN_BMC2DOMO_GET_NAME)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_ADD_COMMAND)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_SET_CMD_SYNTAX)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand,
        PSLAP_STRING_ARRAY          ReqArgs,  
        PSLAP_STRING_ARRAY          OptArgs
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_SET_CMD_SYNTAX2)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand,
        char*                       pReqArgs,
        char*                       pOptArgs
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_DEL_COMMAND)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_ENABLE_COMMAND)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand,
        BOOL                        bEnable
    );

typedef  SLAP_BOOL
(*PFN_BMC2DOMO_IS_VALID)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       pCommand
    );

typedef  ANSC_STATUS
(*PFN_BMC2DOMO_EXIT)
    (
        ANSC_HANDLE                 hThisObject
    );

/*
 * A Slap Bmc2 Domain Object is created every time when user enters a new menu level. The Bmc2
 * Com Terminal Object may maintain multiple domains, but SCP pages can only be executed within the
 * latest domain. For each domain, there's a list of available commands user can use. This list
 * must be created by the corresponding SCP of the command entering the domain.
 */
#define  SLAP_BMC2_DOMAIN_CLASS_CONTENT                                                     \
    /* duplication of the base object class content */                                      \
    SLAP_SCO_GALLERY_CLASS_CONTENT                                                          \
    /* start of object class content */                                                     \
    PFN_BMC2DOMO_GET_NAME           GetDomainName;                                          \
    PFN_BMC2DOMO_ADD_COMMAND        AddCommand;                                             \
    PFN_BMC2DOMO_SET_CMD_SYNTAX     SetCommandSyntax;                                       \
    PFN_BMC2DOMO_SET_CMD_SYNTAX2    SetCommandSyntaxString;                                 \
    PFN_BMC2DOMO_DEL_COMMAND        DelCommand;                                             \
    PFN_BMC2DOMO_ENABLE_COMMAND     EnableCommand;                                          \
    PFN_BMC2DOMO_IS_VALID           IsCommandValid;                                         \
    PFN_BMC2DOMO_IS_VALID           IsCommandAuthorized;                                    \
    PFN_BMC2DOMO_EXIT               Exit;                                                   \
    PFN_BMC2DOMO_EXIT               ExitToRoot;                                             \
    /* end of object class content */                                                       \

typedef  struct
_SLAP_BMC2_DOMAIN_OBJECT
{
    SLAP_BMC2_DOMAIN_CLASS_CONTENT
}
SLAP_BMC2_DOMAIN_OBJECT,  *PSLAP_BMC2_DOMAIN_OBJECT;

#define  ACCESS_SLAP_BMC2_DOMAIN_OBJECT(p)          \
         ACCESS_CONTAINER(p, SLAP_BMC2_DOMAIN_OBJECT, Linkage)
#define  ACCESS_SLAP_BMC2_DOMAIN_FIELD(f)           \
         ACCESS_FIELD_OFFSET(SLAP_BMC2_DOMAIN_OBJECT, f)


#endif
