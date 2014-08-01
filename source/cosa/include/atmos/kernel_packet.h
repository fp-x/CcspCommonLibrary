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

    module:	kernel_packet.h

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco System  , Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines some basic data types and
        structures on a particular platform.

    ---------------------------------------------------------------

    environment:

        atmos 7.1   and later

    ---------------------------------------------------------------

    author:

        Hua Ding

    ---------------------------------------------------------------

    revision:

        09/10/03    initial revision.

**********************************************************************/


#ifndef  _KERNEL_PACKET_
#define  _KERNEL_PACKET_


/***********************************************************
    PLATFORM DEPENDENT DATA TYPE AND MACRO DEFINITIONS
***********************************************************/

#define  KERNEL_ENABLE_PDO_POOLING                  TRUE
#define  KERNEL_ENABLE_BDO_POOLING                  TRUE

#define  KERNEL_MAX_PDO_POOL_SIZE                   CYAN_POOL1_COUNT * 2
#define  KERNEL_MAX_BDO_POOL_SIZE                   CYAN_POOL1_COUNT


#endif
