/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

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

    MODULE: ansc_asn1_AlgorithmIdentifier_export_api.h

        ASN.1 ANSC Code Generated by Cisco Systems, Inc.

    ---------------------------------------------------------------

    COPYRIGHT:

        Cisco Systems, Inc., 1999 ~ 2003

        All Rights Reserved.

    ---------------------------------------------------------------

    DESCRIPTION:

        The Internal functions defined for ASN.1 objects

        *   ANSC_ASN1_ALGORITHMIDENTIFIER
        *   ANSC_ASN1_PARAMETERS
        *   ANSC_ASN1_DSS_PARMS
        *   ANSC_ASN1_DOMAINPARAMETERS
        *   ANSC_ASN1_VALIDATIONPARMS
        *   ANSC_ASN1_PBMPARAMETER
        *   ANSC_ASN1_DHBMPARAMETER
        *   ANSC_ASN1_CASE5MACPARAMETER
        *   ANSC_ASN1_PKCS12PBEPARAMS
        *   ANSC_ASN1_SIGNATUREALGORITHMIDENTIFIER
        *   ANSC_ASN1_SIGNATUREPARAMETERS
        *   ANSC_ASN1_DIGESTALGORITHMIDENTIFIER
        *   ANSC_ASN1_DHKEYAGREEMENT

    ---------------------------------------------------------------

    ENVIRONMENT:

        platform independent

    ---------------------------------------------------------------

    AUTHOR:

        ASNMAGIC ANSC CODE GENERATOR 1.0

    ---------------------------------------------------------------

    REVISION HISTORY:

        *   05/07/2002  initial revision

 **********************************************************************/


#ifndef  _ANSC_ASN1_ALGORITHMIDENTIFIER_EXPORTED_API_H
#define  _ANSC_ASN1_ALGORITHMIDENTIFIER_EXPORTED_API_H

/**********************************************************************

 OBJECT -- ANSC_ASN1_ALGORITHMIDENTIFIER

 AlgorithmIdentifier ::= Sequence 
     {
                      algorithmOID OID 
                        parameters Parameters 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateAlgorithmIdentifier
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_PARAMETERS

 Parameters ::= Choice 
     {
                         nullParms NULL 
                          dssParms Dss_Parms 
                       octetString OctetString 
                  domainParameters DomainParameters 
                      pbmParameter PBMParameter 
                     dhbmParameter DHBMParameter 
                 case5MacParameter Case5MacParameter 
                   pkcs12PbeParams PKCS12PbeParams 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateParameters
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DSS_PARMS

 Dss_Parms ::= Sequence 
     {
                                 p Integer 
                                 q Integer 
                                 g Integer 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateDss_Parms
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DOMAINPARAMETERS

 DomainParameters ::= Sequence 
     {
                                 p Integer 
                                 g Integer 
                                 q Integer 
                                 j Integer 
                   validationParms ValidationParms 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateDomainParameters
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_VALIDATIONPARMS

 ValidationParms ::= Sequence 
     {
                              seed BitString 
                       pgenCounter Integer 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateValidationParms
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_PBMPARAMETER

 PBMParameter ::= Sequence 
     {
                              salt OctetString 
                               owf AlgorithmIdentifier 
                    iterationCount Integer 
                               mac AlgorithmIdentifier 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreatePBMParameter
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DHBMPARAMETER

 DHBMParameter ::= Sequence 
     {
                               owf AlgorithmIdentifier 
                               mac AlgorithmIdentifier 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateDHBMParameter
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_CASE5MACPARAMETER

 Case5MacParameter ::= Sequence 
     {
                         macLength Integer 
                         keyLength Integer 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateCase5MacParameter
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_PKCS12PBEPARAMS

 PKCS12PbeParams ::= Sequence 
     {
                              salt OctetString 
                        iterations Integer 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreatePKCS12PbeParams
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_SIGNATUREALGORITHMIDENTIFIER

 SignatureAlgorithmIdentifier ::= Sequence 
     {
                      algorithmOID OID 
               signatureParameters SignatureParameters 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateSignatureAlgorithmIdentifier
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_SIGNATUREPARAMETERS

 SignatureParameters ::= Choice 
     {
                         nullParms NULL 
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateSignatureParameters
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DIGESTALGORITHMIDENTIFIER

 DigestAlgorithmIdentifier ::= AlgorithmIdentifier 

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateDigestAlgorithmIdentifier
    (
        ANSC_HANDLE                 hReserved
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DHKEYAGREEMENT

 DHKeyAgreement ::= Sequence 
     {
                                 p Integer 
                                 g Integer 
                       priValueLen Integer OPT
     }

 **********************************************************************/

ANSC_HANDLE 
AnscAsn1CreateDHKeyAgreement
    (
        ANSC_HANDLE                 hReserved
    );


#endif  /* _ANSC_ASN1_ALGORITHMIDENTIFIER_EXPORTED_API_H */


