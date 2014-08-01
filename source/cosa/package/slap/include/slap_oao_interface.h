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

    module:	slap_oao_interface.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines the base class data structure and
        interface for the Slap Obj Agent Objects.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        09/29/03    initial revision.

**********************************************************************/


#ifndef  _SLAP_OAO_INTERFACE_
#define  _SLAP_OAO_INTERFACE_


/*
 * This object is derived a virtual base object defined by the underlying framework. We include the
 * interface header files of the base object here to shield other objects from knowing the derived
 * relationship between this object and its base class.
 */
#include "ansc_lco_interface.h"
#include "ansc_lco_external_api.h"

#include "slap_ifo_goa.h"


/***********************************************************
          SLAP OBJ AGENT COMPONENT OBJECT DEFINITION
***********************************************************/

/*
 * Define some const values that will be used in the os wrapper object definition.
 */
#define  SLAP_OAO_OBJ_MODE_relay                    1
#define  SLAP_OAO_OBJ_MODE_clone                    2
#define  SLAP_OAO_OBJ_MODE_local                    3

/*
 * Since we write all kernel modules in C (due to better performance and lack of compiler support), we
 * have to simulate the C++ object by encapsulating a set of functions inside a data structure.
 */
typedef  ANSC_HANDLE
(*PFN_SLAPOAO_GET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_SET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hContext
    );

typedef  ANSC_HANDLE
(*PFN_SLAPOAO_GET_IF)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_SET_IF)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    );

typedef  ULONG
(*PFN_SLAPOAO_GET_TYPE)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_SET_TYPE)
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       obj_type
    );

typedef  ULONG
(*PFN_SLAPOAO_GET_MODE)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_SET_MODE)
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       obj_mode
    );

typedef  char*
(*PFN_SLAPOAO_GET_NAME)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_SET_NAME)
    (
        ANSC_HANDLE                 hThisObject,
        char*                       obj_name
    );

typedef  BOOL
(*PFN_SLAPOAO_GET_BOOL)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_SET_BOOL)
    (
        ANSC_HANDLE                 hThisObject,
        BOOL                        bValue
    );

typedef  ANSC_STATUS
(*PFN_SLAPOAO_RESET)
    (
        ANSC_HANDLE                 hThisObject
    );

/*
 * The SLAP Obj Agent Object is used to encapsulate a generic object presentation to the upper
 * layer modules. It wraps the actual object handle that is owned by another process. If this
 * object is a 'mobile' object and has been registered in the local process, we create a cloned
 * object which mirrors the data fields of the original object.
 */
#define  SLAP_OBJ_AGENT_CLASS_CONTENT                                                       \
    /* duplication of the base object class content */                                      \
    ANSCLCO_CLASS_CONTENT                                                                   \
    /* start of object class content */                                                     \
    ULONG                           ObjType;                                                \
    ULONG                           ObjMode;                                                \
    char*                           ObjName;                                                \
    ANSC_HANDLE                     hOriginalObj;                                           \
    ANSC_HANDLE                     hClonedObj;                                             \
    BOOL                            bDirty;                                                 \
                                                                                            \
    PFN_SLAPOAO_SET_NAME            SetObjName;                                             \
    /* end of object class content */                                                       \

typedef  struct
_SLAP_OBJ_AGENT_OBJECT
{
    SLAP_OBJ_AGENT_CLASS_CONTENT
}
SLAP_OBJ_AGENT_OBJECT,  *PSLAP_OBJ_AGENT_OBJECT;

#define  ACCESS_SLAP_OBJ_AGENT_OBJECT(p)            \
         ACCESS_CONTAINER(p, SLAP_OBJ_AGENT_OBJECT, Linkage)
#define  ACCESS_SLAP_OBJ_AGENT_FIELD(f)             \
         ACCESS_FIELD_OFFSET(SLAP_OBJ_AGENT_OBJECT, f)


#endif
