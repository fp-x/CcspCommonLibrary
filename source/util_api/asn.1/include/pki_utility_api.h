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

    MODULE: pki_utility_api.h

        ASN.1 ANSC Code Generated by Cisco Systems, Inc.

    ---------------------------------------------------------------

    COPYRIGHT:

        Cisco Systems, Inc., 1999 ~ 2003

        All Rights Reserved.

    ---------------------------------------------------------------

    DESCRIPTION:

        The utility apis for PKI implementation

        *   PKIUtilityInitKeyGenParams
        *   PKIUtilityGetPrivateKeyInfoEncoding

    ---------------------------------------------------------------

    ENVIRONMENT:

        platform independent

    ---------------------------------------------------------------

    AUTHOR:

        Bin Zhu

    ---------------------------------------------------------------

    REVISION HISTORY:

        *   09/11/2002  initial revision

 **********************************************************************/


#ifndef  _PKI_UTILITY_API_H
#define  _PKI_UTILITY_API_H

/*************************************************************************
 *
 * This is the api to init the KeyGenParams from the given certificate
 * and private key info
 *
 *************************************************************************/
ANSC_STATUS
PKIUtilityInitKeyGenParams
    (
        ANSC_HANDLE                         hSSLCrypto,
        PANSC_ASN1_CERTIFICATE              pCert,
        PANSC_ASN1_PRIVATEKEYINFO           pKeyInfo,
        ANSC_HANDLE                         hKeyGenParams
    );

/*************************************************************************
 *
 * This is the reverse api of above, with the given key type and KeyGenParams,
 * generate the private key info encoding;
 *
 *************************************************************************/
PUCHAR
PKIUtilityGetPrivateKeyInfoEncoding
    (
        ANSC_HANDLE                 hKeyGenParams,
        PKI_KEY_TYPE                keyType,
        PULONG                      pLength
    );

#endif  /*_PKI_UTILITY_API_H*/


