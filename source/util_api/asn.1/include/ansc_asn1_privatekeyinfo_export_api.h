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

    MODULE: ansc_asn1_PrivateKeyInfo_export_api.h

        ASN.1 ANSC Code Generated by Cisco Systems, Inc.

    ---------------------------------------------------------------

    COPYRIGHT:

        Cisco Systems, Inc., 1999 ~ 2003

        All Rights Reserved.

    ---------------------------------------------------------------

    DESCRIPTION:

        The Internal functions defined for ASN.1 objects

        *   ANSC_ASN1_ENCRYPTEDPRIVATEKEYINFO
        *   ANSC_ASN1_ENCRYPTIONALGORITHMIDENTIFIER
        *   ANSC_ASN1_PRIVATEKEYINFO
        *   ANSC_ASN1_PRIVATEKEY
        *   ANSC_ASN1_RSAPRIVATEKEY
        *   ANSC_ASN1_DSAPRIVATEKEY


    ---------------------------------------------------------------

    ENVIRONMENT:

        platform independent

    ---------------------------------------------------------------

    AUTHOR:

        ASNMAGIC ANSC CODE GENERATOR 1.0

    ---------------------------------------------------------------

    REVISION HISTORY:

        *   05/01/2002  initial revision

 **********************************************************************/


#ifndef  _ANSC_ASN1_PRIVATEKEYINFO_EXPORTED_API_H
#define  _ANSC_ASN1_PRIVATEKEYINFO_EXPORTED_API_H

/**********************************************************************

 OBJECT -- ANSC_ASN1_ENCRYPTEDPRIVATEKEYINFO

 EncryptedPrivateKeyInfo ::= Sequence 
     {
               encryptionAlgorithm EncryptionAlgorithmIdentifier 
                     encryptedData OctetString 
         EXTRA:
                     privateKeyInfo PrivateKeyInfo 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateEncryptedPrivateKeyInfo
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_ENCRYPTIONALGORITHMIDENTIFIER

 EncryptionAlgorithmIdentifier ::= AlgorithmIdentifier 

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateEncryptionAlgorithmIdentifier
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_PRIVATEKEYINFO

 PrivateKeyInfo ::= Sequence 
     {
                           version Integer 
               privateKeyAlgorithm AlgorithmIdentifier 
                   privateKeyOctet OctetString 
                        attributes [CON 0] IMP Attributes OPT
         EXTRA:
                         privateKey PrivateKey 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreatePrivateKeyInfo
    (
        ANSC_HANDLE                 hReserved
    );

ANSC_HANDLE 
AnscAsn1CreatePrivateKeyInfoWithKey
    (
        ANSC_HANDLE                 hReserved,
        PKI_KEY_TYPE                keyType,
        ANSC_HANDLE                 hKeyGenParams
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_PRIVATEKEY

 PrivateKey ::= Choice 
     {
                     rsaPrivateKey RSAPrivateKey 
                     dsaPrivateKey DSAPrivateKey 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreatePrivateKey
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_RSAPRIVATEKEY

 RSAPrivateKey ::= Sequence 
     {
                           version Integer 
                           modulus Integer 
                    publicExponent Integer 
                   privateExponent Integer 
                            prime1 Integer 
                            prime2 Integer 
                         exponent1 Integer 
                         exponent2 Integer 
                       coefficient Integer 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateRSAPrivateKey
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DSAPRIVATEKEY

 DSAPrivateKey ::= Sequence 
     {
                                 p Integer 
                                 q Integer 
                                 g Integer 
                                 y Integer 
                                 x Integer 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateDSAPrivateKey
    (
        ANSC_HANDLE                 hReserved
    );


#endif  /*_ANSC_ASN1_PRIVATEKEYINFO_EXPORTED_API_H*/


