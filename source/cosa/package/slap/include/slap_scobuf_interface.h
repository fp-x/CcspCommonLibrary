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

    module:	slap_scobuf_interface.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines the base class data structure and
        interface for the Slap Sco Buffer Objects.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        07/14/03    initial revision.

**********************************************************************/


#ifndef  _SLAP_SCOBUF_INTERFACE_
#define  _SLAP_SCOBUF_INTERFACE_


/*
 * This object is derived a virtual base object defined by the underlying framework. We include the
 * interface header files of the base object here to shield other objects from knowing the derived
 * relationship between this object and its base class.
 */
#include "slap_scostd_interface.h"
#include "slap_scostd_exported_api.h"


/***********************************************************
          SLAP BUFFER SCO BUFFER OBJECT DEFINITION
***********************************************************/

/*
 * Define some const values that will be used in the os wrapper object definition.
 */

/*
 * Since we write all kernel modules in C (due to better performance and lack of compiler support), we
 * have to simulate the C++ object by encapsulating a set of functions inside a data structure.
 */
typedef  ANSC_HANDLE
(*PFN_SLAPSCOBUF_GET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOBUF_SET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hContext
    );

typedef  ANSC_HANDLE
(*PFN_SLAPSCOBUF_GET_IF)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOBUF_SET_IF)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    );

typedef  SLAP_UINT32
(*PFN_SLAPSCOBUF_GET_SIZE)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  SLAP_UCHAR_ARRAY*
(*PFN_SLAPSCOBUF_GET_DATA)
    (
        ANSC_HANDLE                 hThisObject
    );

/*
 * The SLAP Sco Buffer Object is derived from the SLAP Sco Standard Object. It encapsulates the
 * generic data access interface to any binary buffer type of data structure. This object can be
 * derived to encapsulate the binary data access to network packet, memory block, or any other
 * data type that requires serialized binary access.
 */
#define  SLAP_SCO_BUFFER_CLASS_CONTENT                                                      \
    /* duplication of the base object class content */                                      \
    SLAP_SCO_STANDARD_CLASS_CONTENT                                                         \
    /* start of object class content */                                                     \
    PFN_SLAPSCOBUF_GET_SIZE         GetSize;                                                \
    PFN_SLAPSCOBUF_GET_DATA         GetData;                                                \
    /* end of object class content */                                                       \

typedef  struct
_SLAP_SCO_BUFFER_OBJECT
{
    SLAP_SCO_BUFFER_CLASS_CONTENT
}
SLAP_SCO_BUFFER_OBJECT,  *PSLAP_SCO_BUFFER_OBJECT;

#define  ACCESS_SLAP_SCO_BUFFER_OBJECT(p)           \
         ACCESS_CONTAINER(p, SLAP_SCO_BUFFER_OBJECT, Linkage)
#define  ACCESS_SLAP_SCO_BUFFER_FIELD(f)            \
         ACCESS_FIELD_OFFSET(SLAP_SCO_BUFFER_OBJECT, f)


#endif
