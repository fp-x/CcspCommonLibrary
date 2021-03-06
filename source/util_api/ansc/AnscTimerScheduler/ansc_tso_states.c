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

    module:	ansc_tso_states.c

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced state-access functions
        of the Ansc Timer Scheduler Object.

        *   AnscTsoReset

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        10/14/01    initial revision.

**********************************************************************/


#include "ansc_tso_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscTsoReset
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to reset the object states.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscTsoReset
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus     = ANSC_STATUS_SUCCESS;
    PANSC_TIMER_SCHEDULER_OBJECT    pMyObject        = (PANSC_TIMER_SCHEDULER_OBJECT)hThisObject;
    PANSC_TIMER_DESCRIPTOR_OBJECT   pTimerDescriptor = NULL;
    PSINGLE_LINK_ENTRY              pSLinkEntry      = NULL;

    AnscAcquireSpinLock      (&pMyObject->TdoQueueSpinLock);
    AnscQueueInitializeHeader(&pMyObject->TdoQueue        );
    AnscReleaseSpinLock      (&pMyObject->TdoQueueSpinLock);

    pMyObject->hCurInvokedTdo = (ANSC_HANDLE)NULL;

    return  ANSC_STATUS_SUCCESS;
}
