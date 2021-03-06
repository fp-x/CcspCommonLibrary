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

    module:	ansc_mco_control.c

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced if-contrl functions
        of the Ansc Module Container Object.

        *   AnscMcoRegisterIfs
        *   AnscMcoDispatchIfs

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        05/13/02    initial revision.

**********************************************************************/


#include "ansc_mco_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscMcoRegisterIfs
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to register all the interface objects.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscMcoRegisterIfs
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus   = ANSC_STATUS_SUCCESS;
    PANSC_MODULE_CONTAINER_OBJECT   pMyObject      = (PANSC_MODULE_CONTAINER_OBJECT)hThisObject;
    PANSC_QUERY_INTERFACE_OBJECT    pQueryIfObject = (PANSC_QUERY_INTERFACE_OBJECT )pMyObject->hQueryIfObject;

    return  ANSC_STATUS_UNAPPLICABLE;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscMcoDispatchIfs
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hIqcIf
            );

    description:

        This function is called to dispatch all the interface objects.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hIqcIf
                Specifies the Interface Query Controller Interface.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscMcoDispatchIfs
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hIqcIf
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_MODULE_CONTAINER_OBJECT   pMyObject    = (PANSC_MODULE_CONTAINER_OBJECT)hThisObject;
    PANSC_IQC_INTERFACE             pIqcIf       = (PANSC_IQC_INTERFACE          )hIqcIf;

    return  ANSC_STATUS_UNAPPLICABLE;
}
