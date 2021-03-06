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

    module:	ansc_tmo_external_api.h

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco System  , Inc., 1997 ~ 2001
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the external functions provided by the Trunk Manager.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        08/01/01    initial revision.

**********************************************************************/


#ifndef  _ANSC_TMO_EXTERNAL_API_
#define  _ANSC_TMO_EXTERNAL_API_


/***********************************************************
        FUNCTIONS IMPLEMENTED IN ANSC_TMO_INTERFACE.C
***********************************************************/

ANSC_HANDLE
AnscCreateTrunkManager
    (
        ANSC_HANDLE                 hOwnerContext
    );

ANSC_HANDLE
AnscCreateTmoIp4
    (
        ANSC_HANDLE                 hOwnerContext
    );

ANSC_HANDLE
AnscCreateTmoTcp
    (
        ANSC_HANDLE                 hOwnerContext
    );

ANSC_HANDLE
AnscCreateTmoUdp
    (
        ANSC_HANDLE                 hOwnerContext
    );

ANSC_HANDLE
AnscCreateTmoEsp
    (
        ANSC_HANDLE                 hOwnerContext
    );

ANSC_HANDLE
AnscCreateTmoAh
    (
        ANSC_HANDLE                 hOwnerContext
    );

ANSC_HANDLE
AnscCreateTmoIpcomp
    (
        ANSC_HANDLE                 hOwnerContext
    );


#endif
