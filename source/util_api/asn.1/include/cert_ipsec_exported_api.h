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

    module: cert_ipsec_exported_api.h

        For BroadWay Service Delivery System (BISGA)

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2004
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file contains the prototype definition for all
        the exported functions provided by the Cert Ipsec Manager
        Object.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Bin Zhu

    ---------------------------------------------------------------

    revision:

        03/17/2004    initial revision.

**********************************************************************/


#ifndef  _CERT_IPSEC_MGR_EXPORTED_API_
#define  _CERT_IPSEC_MGR_EXPORTED_API_


/***********************************************************
        FUNCTIONS IMPLEMENTED IN CERT_IPSECMGR_INTERFACE.C
***********************************************************/

ANSC_HANDLE
PkiCreateCertIpsecManager
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );


/***********************************************************
          FUNCTIONS IMPLEMENTED IN CERT_IPSECMGR_BASE.C
***********************************************************/

ANSC_HANDLE
CertIpsecMgrCreate
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    );

ANSC_STATUS
CertIpsecMgrRemove
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
CertIpsecMgrEnrollObjects
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
CertIpsecMgrInitialize
    (
        ANSC_HANDLE                 hThisObject
    );


#endif
