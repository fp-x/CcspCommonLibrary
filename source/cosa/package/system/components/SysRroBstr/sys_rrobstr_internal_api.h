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

    module:	sys_rrobstr_internal_api.h

        For BroadWay Runtime System Environment (SYS),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the internal functions provided by the Sys Rro Bstr Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        05/07/02    initial revision.

**********************************************************************/


#ifndef  _SYS_RROBSTR_INTERNAL_API_
#define  _SYS_RROBSTR_INTERNAL_API_


/***********************************************************
        FUNCTIONS IMPLEMENTED IN SYS_RROBSTR_ACCESS.C
***********************************************************/

ANSC_STATUS
SysRroBstrGetRecordData
    (
        ANSC_HANDLE                 hThisObject,
        PVOID                       pDataBuffer,
        PULONG                      pulDataSize
    );

ANSC_STATUS
SysRroBstrSetRecordData
    (
        ANSC_HANDLE                 hThisObject,
        PVOID                       pDataBuffer,
        ULONG                       ulDataSize
    );

PUCHAR
SysRroBstrGetRecordValue
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
SysRroBstrSetRecordValue
    (
        ANSC_HANDLE                 hThisObject,
        PUCHAR                      value,
        ULONG                       size
    );


#endif
