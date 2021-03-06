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

    module:	http_spo_cbc.c

        For HyperText Transfer Protocol Implementation (HTTP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced interface functions
        of the Http Simple Proxy Object.

        *   HttpSpoCbcReplyHeaders
        *   HttpSpoCbcReplyBody

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        02/26/02    initial revision.

**********************************************************************/


#include "http_spo_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ULONG
        HttpSpoCbcReplyHeaders
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hSession,
                ANSC_HANDLE                 hMessage
            );

    description:

        This function is called to control the proxy's behavior.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hSession
                Specifies the parameter for SBC object to process.

                ANSC_HANDLE                 hMessage
                Specifies the parameter for SBC object to process.

    return:     process mode.

**********************************************************************/

ULONG
HttpSpoCbcReplyHeaders
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hSession,
        ANSC_HANDLE                 hMessage
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_SIMPLE_PROXY_OBJECT       pMyObject    = (PHTTP_SIMPLE_PROXY_OBJECT  )hThisObject;
    PHTTP_SIMPLE_PROXY_PROPERTY     pProperty    = (PHTTP_SIMPLE_PROXY_PROPERTY)&pMyObject->Property;
    PHTTP_PROXY_SESSION_OBJECT      pSession     = (PHTTP_PROXY_SESSION_OBJECT )hSession;
    PHTTP_BMO_REP_OBJECT            pBmoRep      = (PHTTP_BMO_REP_OBJECT       )hMessage;

    return  HTTP_CBC_PMODE_RELAY2;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ULONG
        HttpSpoCbcReplyBody
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hSession,
                ANSC_HANDLE                 hMessage
            );

    description:

        This function is called to control the proxy's behavior.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hSession
                Specifies the parameter for SBC object to process.

                ANSC_HANDLE                 hMessage
                Specifies the parameter for SBC object to process.

    return:     process mode.

**********************************************************************/

ULONG
HttpSpoCbcReplyBody
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hSession,
        ANSC_HANDLE                 hMessage
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PHTTP_SIMPLE_PROXY_OBJECT       pMyObject    = (PHTTP_SIMPLE_PROXY_OBJECT  )hThisObject;
    PHTTP_SIMPLE_PROXY_PROPERTY     pProperty    = (PHTTP_SIMPLE_PROXY_PROPERTY)&pMyObject->Property;
    PHTTP_PROXY_SESSION_OBJECT      pSession     = (PHTTP_PROXY_SESSION_OBJECT )hSession;
    PHTTP_BMO_REP_OBJECT            pBmoRep      = (PHTTP_BMO_REP_OBJECT       )hMessage;

    return  HTTP_CBC_PMODE_RELAY2;
}
