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

    MODULE: ansc_asn1_CertificateRequest_internal.h

        ASN.1 ANSC Code Generated by Cisco Systems, Inc.

    ---------------------------------------------------------------

    COPYRIGHT:

        Cisco Systems, Inc., 1999 ~ 2003

        All Rights Reserved.

    ---------------------------------------------------------------

    DESCRIPTION:

        The Internal functions defined for ASN.1 objects

        *   ANSC_ASN1_CERTIFICATEREQUEST
        *   ANSC_ASN1_CERTIFICATIONREQUESTINFO


    ---------------------------------------------------------------

    ENVIRONMENT:

        platform independent

    ---------------------------------------------------------------

    AUTHOR:

        ASNMAGIC ANSC CODE GENERATOR 1.0

    ---------------------------------------------------------------

    REVISION HISTORY:

        *   04/29/2002  initial revision

 **********************************************************************/


#ifndef  _ANSC_ASN1_CERTIFICATEREQUEST_INTERNAL_H
#define  _ANSC_ASN1_CERTIFICATEREQUEST_INTERNAL_H

/**********************************************************************

 OBJECT -- ANSC_ASN1_CERTIFICATEREQUEST

 CertificateRequest ::= Sequence 
     {
            certificateRequestInfo CertificationRequestInfo 
      signatureAlgorithmIdentifier SignatureAlgorithmIdentifier 
                         signature BitString 
     }

 **********************************************************************/

PANSC_ATTR_OBJECT
AnscAsn1CertificateRequestCreateChildAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PCHAR
AnscAsn1CertificateRequestGetChildName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

ANSC_HANDLE
AnscAsn1CertificateRequestCreateChildObject
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

ANSC_HANDLE
AnscAsn1CertificateRequestGetCertificateRequestInfo
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_HANDLE
AnscAsn1CertificateRequestGetSignatureAlgorithmIdentifier
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_HANDLE
AnscAsn1CertificateRequestGetSignature
    (
        ANSC_HANDLE                 hThisObject
    );

/*
 *  Manually added functions;
 */
ANSC_STATUS
AnscAsn1CertificateRequestFree
    (
        ANSC_HANDLE                 hThisObject
    );

SIGNATURE_TYPE
AnscAsn1PKCS10GetSignatureType
    (
        ANSC_HANDLE                 hThisObject
    );

BOOLEAN
AnscAsn1PKCS10SetSignatureAlg
    (
        ANSC_HANDLE                 hThisObject,
        SIGNATURE_TYPE              signType
    );

BOOLEAN
AnscAsn1PKCS10SetPublicKeyInfo
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hKeyHandle
    );

ANSC_HANDLE
AnscAsn1PKCS10GetSubjectHandle
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
AnscAsn1PKCS10BeforeDecodingChild
    (
        ANSC_HANDLE                 hThisObject,
        int                         index,
        PVOID*                      ppEncoding
    );

ANSC_STATUS
AnscAsn1PKCS10AfterDecodingChild
    (
        ANSC_HANDLE                 hThisObject,
        int                         index,
        PVOID*                      ppEncoding
    );

ANSC_STATUS
AnscAsn1PKCS10AfterDecoding
    (
        ANSC_HANDLE                 hThisObject,
        PVOID*                      ppEncoding
    );

BOOLEAN
AnscAsn1PKCS10Verify
    (
        ANSC_HANDLE                 hThisObject
    );

BOOLEAN
AnscAsn1PKCS10InitName
    (
        ANSC_HANDLE                 hThisObject,
        PALCERTIFICATE_ATTRIBUTE    pAttrObject
    );

BOOLEAN
AnscAsn1PKCS10SignWithPrivateKeyInfo
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hPrivateKeyInfo
    );

BOOLEAN
AnscAsn1PKCS10SignWithCryptAPI
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hCryptAPI
    );

BOOLEAN
AnscAsn1PKCS10SignWithKeyParam
    (
        ANSC_HANDLE                 hThisObject,
        PKI_KEY_TYPE                keyType,
        ANSC_HANDLE                 hCryptAPI
    );

BOOLEAN
AnscAsn1PKCS10InitKeyPair
    (
        ANSC_HANDLE                 hThisObject,
        PKI_KEY_TYPE                keyType,
        ANSC_HANDLE                 hKeyPairHandle
    );

BOOLEAN
AnscAsn1PKCS10InitWithCryptoAPI
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hCryptAPI
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_CERTIFICATIONREQUESTINFO

 CertificationRequestInfo ::= Sequence 
     {
                           version Integer 
                           subject Name 
                     subjectPKInfo SubjectPublicKeyInfo 
                        attributes [CON 0] IMP Attributes OPT
     }

 **********************************************************************/

PANSC_ATTR_OBJECT
AnscAsn1CertificationRequestInfoCreateChildAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PCHAR
AnscAsn1CertificationRequestInfoGetChildName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

ANSC_HANDLE
AnscAsn1CertificationRequestInfoCreateChildObject
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );


#endif  /*_ANSC_ASN1_CERTIFICATEREQUEST_INTERNAL_H*/

