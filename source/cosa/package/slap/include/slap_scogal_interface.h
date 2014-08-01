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

    module:	slap_scogal_interface.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines the base class data structure and
        interface for the Slap Sco Gallery Objects.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        07/15/03    initial revision.

**********************************************************************/


#ifndef  _SLAP_SCOGAL_INTERFACE_
#define  _SLAP_SCOGAL_INTERFACE_


/*
 * This object is derived a virtual base object defined by the underlying framework. We include the
 * interface header files of the base object here to shield other objects from knowing the derived
 * relationship between this object and its base class.
 */
#include "slap_scocol_interface.h"
#include "slap_scocol_exported_api.h"


/***********************************************************
         SLAP STANDARD SCO GALLERY OBJECT DEFINITION
***********************************************************/

/*
 * Define some const values that will be used in the os wrapper object definition.
 */

/*
 * Since we write all kernel modules in C (due to better performance and lack of compiler support), we
 * have to simulate the C++ object by encapsulating a set of functions inside a data structure.
 */
typedef  ANSC_HANDLE
(*PFN_SLAPSCOGAL_GET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_SET_CONTEXT)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hContext
    );

typedef  ANSC_HANDLE
(*PFN_SLAPSCOGAL_GET_IF)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_SET_IF)
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_INIT_ATO)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  SLAP_VARIABLE*
(*PFN_SLAPSCOGAL_GET_VAR)
    (
        ANSC_HANDLE                 hThisObject,
        SLAP_PARAMETER_LIST*        param_list
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_SET_VAR)
    (
        ANSC_HANDLE                 hThisObject,
        SLAP_PARAMETER_LIST*        param_list
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_ADD_VAR)
    (
        ANSC_HANDLE                 hThisObject,
        SLAP_PARAMETER_LIST*        param_list
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_DEL_VAR)
    (
        ANSC_HANDLE                 hThisObject,
        SLAP_PARAMETER_LIST*        param_list
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_DEL_ALL)
    (
        ANSC_HANDLE                 hThisObject
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_JOIN)
    (
        ANSC_HANDLE                 hThisObject,
        SLAP_VARIABLE*              gallery_var
    );

typedef  ANSC_STATUS
(*PFN_SLAPSCOGAL_QUIT)
    (
        ANSC_HANDLE                 hThisObject,
        SLAP_VARIABLE*              gallery_var
    );

/*
 * The SLAP Sco Gallery Object is derived from the base Sco Collection Object. This object can be
 * derived to management variable collection in runtime. Unlike other System.Utility objects, the
 * Var Gallery Object is not created by the system container, but rather serves as a base virtual
 * object for the external modules that need a more advanced collection management.
 */
#define  SLAP_SCO_GALLERY_CLASS_CONTENT                                                     \
    /* duplication of the base object class content */                                      \
    SLAP_SCO_COLLECTION_CLASS_CONTENT                                                       \
    /* start of object class content */                                                     \
    ANSC_HANDLE                     hAtoVariable;                                           \
    BOOL                            bOlmEnabled;                                            \
                                                                                            \
    PFN_SLAPSCOGAL_GET_IF           GetSlapGoaIf;                                           \
    PFN_SLAPSCOGAL_GET_CONTEXT      GetOlmContainer;                                        \
                                                                                            \
    PFN_SLAPSCOGAL_GET_VAR          GetVariable;                                            \
    PFN_SLAPSCOGAL_SET_VAR          SetVariable;                                            \
    PFN_SLAPSCOGAL_ADD_VAR          AddVariable;                                            \
    PFN_SLAPSCOGAL_DEL_VAR          DelVariable;                                            \
    PFN_SLAPSCOGAL_DEL_ALL          DelAllVariables;                                        \
                                                                                            \
    PFN_SLAPSCOGAL_JOIN             JoinGallery;                                            \
    PFN_SLAPSCOGAL_QUIT             QuitGallery;                                            \
    /* end of object class content */                                                       \

typedef  struct
_SLAP_SCO_GALLERY_OBJECT
{
    SLAP_SCO_GALLERY_CLASS_CONTENT
}
SLAP_SCO_GALLERY_OBJECT,  *PSLAP_SCO_GALLERY_OBJECT;

#define  ACCESS_SLAP_SCO_GALLERY_OBJECT(p)          \
         ACCESS_CONTAINER(p, SLAP_SCO_GALLERY_OBJECT, Linkage)
#define  ACCESS_SLAP_SCO_GALLERY_FIELD(f)           \
         ACCESS_FIELD_OFFSET(SLAP_SCO_GALLERY_OBJECT, f)


#endif
