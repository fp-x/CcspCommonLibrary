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

    module:	slap_bmc2appo_interface.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines all the platform-independent
        functions and macros for the Slap Bmc2 Application Object.

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


#ifndef  _SLAP_BMC2APPO_INTERFACE_
#define  _SLAP_BMC2APPO_INTERFACE_


/*
 * This object is derived a virtual base object defined by the underlying framework. We include the
 * interface header files of the base object here to shield other objects from knowing the derived
 * relationship between this object and its base class.
 */
#include "slap_scogal_interface.h"
#include "slap_scogal_exported_api.h"


/***********************************************************
      SLAP BMC2 APPLICATION COMPONENT OBJECT DEFINITION
***********************************************************/

/*
 * Define some const values that will be used in the object mapper object definition.
 */
#define  SLAP_BMC2APPO_UOA_NAME                     "Services.Bmc2.Application"

/*
 * Since we write all kernel modules in C (due to better performance and lack of compiler support),
 * we have to simulate the C++ object by encapsulating a set of functions inside a data structure.
 */
typedef  ANSC_HANDLE
(*PFN_BMC2APPO_GET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_BMC2APPO_SET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hContext
    );

typedef  ANSC_HANDLE
(*PFN_BMC2APPO_GET_IF)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_BMC2APPO_SET_IF)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    );

typedef  ANSC_STATUS
(*PFN_BMC2APPO_LOCK)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_BMC2APPO_UNLOCK)
    (
        ANSC_HANDLE                 hThisObject
    );

/*
 * The Slap Bmc2 Application Object is created when the first remote console user logs in via
 * either Telnet or some other means. It provides a repository for storing variables and object
 * references that are available to all the pages that all visitors open.
 */
#define  SLAP_BMC2_APPLICATION_CLASS_CONTENT                                                \
    /* duplication of the base object class content */                                      \
    SLAP_SCO_GALLERY_CLASS_CONTENT                                                          \
    /* start of object class content */                                                     \
    ANSC_LOCK                       AccessLock;                                             \
                                                                                            \
    PFN_BMC2APPO_LOCK               Lock;                                                   \
    PFN_BMC2APPO_UNLOCK             Unlock;                                                 \
    /* end of object class content */                                                       \

typedef  struct
_SLAP_BMC2_APPLICATION_OBJECT
{
    SLAP_BMC2_APPLICATION_CLASS_CONTENT
}
SLAP_BMC2_APPLICATION_OBJECT,  *PSLAP_BMC2_APPLICATION_OBJECT;

#define  ACCESS_SLAP_BMC2_APPLICATION_OBJECT(p)     \
         ACCESS_CONTAINER(p, SLAP_BMC2_APPLICATION_OBJECT, Linkage)
#define  ACCESS_SLAP_BMC2_APPLICATION_FIELD(f)      \
         ACCESS_FIELD_OFFSET(SLAP_BMC2_APPLICATION_OBJECT, f)


#endif
