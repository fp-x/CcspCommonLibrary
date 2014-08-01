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

    module:	http_atocgienv_exported_api.h

        For HyperText Transfer Protocol Implementation (HTTP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Http Ato CgiEnv
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        03/14/02    initial revision.

**********************************************************************/


#ifndef  _HTTP_ATOCGIENV_EXPORTED_API_
#define  _HTTP_ATOCGIENV_EXPORTED_API_


/***********************************************************
    FUNCTIONS IMPLEMENTED IN HTTP_ATOCGIENV_INTERFACE.C
***********************************************************/

ANSC_HANDLE
HttpCreateAtoCgiEnv
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
       FUNCTIONS IMPLEMENTED IN HTTP_ATOCGIENV_BASE.C
***********************************************************/

ANSC_HANDLE
HttpAtoCgiEnvCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
HttpAtoCgiEnvRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
HttpAtoCgiEnvEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
HttpAtoCgiEnvInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
