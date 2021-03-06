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

    module:	bspeng_writer_co_base.c

        For BSP Engine Writer Component Object,
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the basic component object functions
        of the string Component Object.

        *   BspTemplateWriterCOCreate
        *   BspTemplateWriterCORemove

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Kang Quan

    ---------------------------------------------------------------

    revision:

        05/14/03    initial revision.

**********************************************************************/


#include "bspeng_co_global.h"


/**********************************************************************

    caller:     owner of the object

    prototype:

        ANSC_HANDLE
        BspTemplateWriterCOCreate
            (
                ANSC_HANDLE                 hContainerContext,
                ANSC_HANDLE                 hOwnerContext,
                ANSC_HANDLE                 hAnscReserved
            );

    description:

        This function constructs the String Component object and
        initializes the member variables and functions.

    argument:   ANSC_HANDLE                 hContainerContext
                This handle is used by the container object to interact
                with the outside world. It could be the real container
                or an target object.

                ANSC_HANDLE                 hOwnerContext
                This handle is passed in by the owner of this object.

                ANSC_HANDLE                 hAnscReserved
                This handle is passed in by the owner of this object.

    return:     newly created string component object.

**********************************************************************/

ANSC_HANDLE
BspTemplateWriterCOCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    )
{
    PBSP_TEMPLATE_WRITER_OBJECT     pMyObject    = NULL;

    /*
     * We create object by first allocating memory for holding the variables and member functions.
     */
    pMyObject = (PBSP_TEMPLATE_WRITER_OBJECT)AnscAllocateMemory(sizeof(BSP_TEMPLATE_WRITER_OBJECT));

    if ( !pMyObject )
    {
        return  (ANSC_HANDLE)NULL;
    }

    pMyObject->Initialize                   = BspTemplateWriterCOInitialize;
    pMyObject->Remove                       = BspTemplateWriterCORemove;

    pMyObject->Initialize((ANSC_HANDLE)pMyObject);

    return  (ANSC_HANDLE)pMyObject;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        BspTemplateWriterCORemove
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function destroys the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
BspTemplateWriterCORemove
    (
        ANSC_HANDLE                 hThisObject
    )
{
    PBSP_TEMPLATE_WRITER_OBJECT     pMyObject    = (PBSP_TEMPLATE_WRITER_OBJECT)hThisObject;

    AnscFreeMemory((ANSC_HANDLE)pMyObject);

    return  ANSC_STATUS_SUCCESS;
}


ANSC_STATUS
BspTemplateWriterCOInitialize
    (
        ANSC_HANDLE                 hThisObject
    )
{
    PBSP_TEMPLATE_WRITER_OBJECT     pMyObject    = (PBSP_TEMPLATE_WRITER_OBJECT)hThisObject;

    if ( !pMyObject )
    {
        return ANSC_STATUS_FAILURE;
    }

    pMyObject->WriteBytes                   = BspTemplateWriterWriteBytes;

    pMyObject->Write                        = BspTemplateWriterWrite;
    pMyObject->WriteChar                    = BspTemplateWriterWriteChar;
    pMyObject->WriteDouble                  = BspTemplateWriterWriteDouble;
    pMyObject->WriteHex                     = BspTemplateWriterWriteHex;
    pMyObject->WriteInt                     = BspTemplateWriterWriteInt;
    pMyObject->WriteLong                    = BspTemplateWriterWriteLong;
    pMyObject->WriteString                  = BspTemplateWriterWriteString;
    pMyObject->WriteUint                    = BspTemplateWriterWriteUint;
    pMyObject->WriteUlong                   = BspTemplateWriterWriteUlong;

    pMyObject->OpenExternal                 = BspTemplateWriterOpenExternal;
    pMyObject->OpenInternal                 = BspTemplateWriterOpenInternal;
    pMyObject->Close                        = BspTemplateWriterClose;
    pMyObject->GetContent                   = BspTemplateWriterGetContent;

    pMyObject->Initialize                   = BspTemplateWriterCOInitialize;
    pMyObject->Remove                       = BspTemplateWriterCORemove;

    return ANSC_STATUS_SUCCESS;
}


