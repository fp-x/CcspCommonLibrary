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

    module:	ansc_object_mapper_interface.c

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the some platform-dependent and
        general utility functions related to object mapper operation.

        *   AnscCreateObjectMapper

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        05/18/01    initial revision.

**********************************************************************/


#include "ansc_object_mapper_global.h"


/**********************************************************************

    caller:     component objects

    prototype:

        ANSC_HANDLE
        AnscCreateObjectMapper
            (
                ANSC_HANDLE                 hOwnerContext
            )

    description:

        This function is called to create a new object mapper object.

    argument:   ANSC_HANDLE                 hOwnerContext
                This context handle is transparent to the object mapper
                wrapper, it's only meanful to the caller.

    return:     handle of the object mapper object.

**********************************************************************/

ANSC_HANDLE
AnscCreateObjectMapper
    (
        ANSC_HANDLE                 hOwnerContext
    )
{
    ANSC_STATUS                     returnStatus  = ANSC_STATUS_SUCCESS;
    PANSC_OBJECT_MAPPER_OBJECT      pObjectMapper = NULL;

    return  AnscOmoCreate(hOwnerContext);
}
