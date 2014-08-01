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

    module:	slap_omo_states.c

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced state-access functions
        of the Slap Obj Mapper Object.

        *   SlapOmoGetRootObjBroker
        *   SlapOmoGetProperty
        *   SlapOmoSetProperty
        *   SlapOmoResetProperty
        *   SlapOmoReset

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        07/04/03    initial revision.

**********************************************************************/


#include "slap_omo_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_HANDLE
        SlapOmoGetRootObjBroker
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to retrieve object state.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     object state.

**********************************************************************/

ANSC_HANDLE
SlapOmoGetRootObjBroker
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PSLAP_OBJ_MAPPER_OBJECT         pMyObject    = (PSLAP_OBJ_MAPPER_OBJECT  )hThisObject;
    PSLAP_OBJ_MAPPER_PROPERTY       pProperty    = (PSLAP_OBJ_MAPPER_PROPERTY)&pMyObject->Property;

    return  pMyObject->hRootObjBroker;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        SlapOmoGetProperty
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hProperty
            );

    description:

        This function is called to retrieve object property.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hProperty
                Specifies the property data structure to be filled.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
SlapOmoGetProperty
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hProperty
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PSLAP_OBJ_MAPPER_OBJECT         pMyObject    = (PSLAP_OBJ_MAPPER_OBJECT  )hThisObject;
    PSLAP_OBJ_MAPPER_PROPERTY       pProperty    = (PSLAP_OBJ_MAPPER_PROPERTY)&pMyObject->Property;

    *(PSLAP_OBJ_MAPPER_PROPERTY)hProperty = *pProperty;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        SlapOmoSetProperty
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hProperty
            );

    description:

        This function is called to configure object property.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hProperty
                Specifies the property data structure to be copied.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
SlapOmoSetProperty
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hProperty
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PSLAP_OBJ_MAPPER_OBJECT         pMyObject    = (PSLAP_OBJ_MAPPER_OBJECT  )hThisObject;
    PSLAP_OBJ_MAPPER_PROPERTY       pProperty    = (PSLAP_OBJ_MAPPER_PROPERTY)&pMyObject->Property;

    *pProperty = *(PSLAP_OBJ_MAPPER_PROPERTY)hProperty;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        SlapOmoResetProperty
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to reset object property.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
SlapOmoResetProperty
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PSLAP_OBJ_MAPPER_OBJECT         pMyObject    = (PSLAP_OBJ_MAPPER_OBJECT  )hThisObject;
    PSLAP_OBJ_MAPPER_PROPERTY       pProperty    = (PSLAP_OBJ_MAPPER_PROPERTY)&pMyObject->Property;

    pProperty->Dummy = 0;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        SlapOmoReset
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to reset object states.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
SlapOmoReset
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus   = ANSC_STATUS_SUCCESS;
    PSLAP_OBJ_MAPPER_OBJECT         pMyObject      = (PSLAP_OBJ_MAPPER_OBJECT  )hThisObject;
    PSLAP_OBJ_MAPPER_PROPERTY       pProperty      = (PSLAP_OBJ_MAPPER_PROPERTY)&pMyObject->Property;
    PSLAP_OBJ_BROKER_OBJECT         pRootObjBroker = (PSLAP_OBJ_BROKER_OBJECT  )pMyObject->hRootObjBroker;

    return  ANSC_STATUS_SUCCESS;
}
