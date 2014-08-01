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

    MODULE: ansc_asn1_Name_internal.h

        ASN.1 ANSC Code Generated by Cisco Systems, Inc.

    ---------------------------------------------------------------

    COPYRIGHT:

        Cisco Systems, Inc., 1999 ~ 2003

        All Rights Reserved.

    ---------------------------------------------------------------

    DESCRIPTION:

        The Internal functions defined for ASN.1 objects

        *   ANSC_ASN1_NAME
        *   ANSC_ASN1_RDNSEQUENCE
        *   ANSC_ASN1_ATTRIBUTE
        *   ANSC_ASN1_RELATIVEDISTINGUISHEDNAME
        *   ANSC_ASN1_ATTRIBUTETYPEANDVALUE
        *   ANSC_ASN1_ATTRIBUTEVALUES
        *   ANSC_ASN1_ATTRIBUTEVALUE
        *   ANSC_ASN1_X520NAME
        *   ANSC_ASN1_UNSTRUCTUREDNAME
        *   ANSC_ASN1_DIRECTORYSTRING
        *   ANSC_ASN1_MESSAGEDIGEST
        *   ANSC_ASN1_SIGNINGTIME
        *   ANSC_ASN1_CHLLENGEPASSWORD
        *   ANSC_ASN1_UNSTRUCTUREDADDRESS
        *   ANSC_ASN1_CONTENTTYPE
        *   ANSC_ASN1_X520COMMONNAME
        *   ANSC_ASN1_X520LOCALITYNAME


    ---------------------------------------------------------------

    ENVIRONMENT:

        platform independent

    ---------------------------------------------------------------

    AUTHOR:

        ASNMAGIC ANSC CODE GENERATOR 1.0

    ---------------------------------------------------------------

    REVISION HISTORY:

        *   05/07/2002  initial revision
        *   09/05/2002  GetCommonName() was added in Name object;

 **********************************************************************/


#ifndef  _ANSC_ASN1_NAME_INTERNAL_H
#define  _ANSC_ASN1_NAME_INTERNAL_H

/**********************************************************************

 OBJECT -- ANSC_ASN1_NAME

 Name ::= Choice 
     {
                       rdnSequence RDNSequence 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1NameCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1NameCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1NameGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1NameGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/*
 *  Manually added functions;
 */
BOOLEAN
AnscAsn1NameInitAttribute
    (
        ANSC_HANDLE                 hThisObject,
        PALCERTIFICATE_ATTRIBUTE    pAttrObject
    );

BOOLEAN
AnscAsn1NameAddRDNAttribute
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString,
        ANSC_HANDLE                 hValueHandle
    );

BOOLEAN
AnscAsn1NameExportToString
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pString,
        PULONG                      pLength
    );

BOOLEAN
AnscAsn1NameGetCommonName
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pString,
        PULONG                      pLength
    );

BOOLEAN
AnscAsn1NameGetNameByOID
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString,
        PCHAR                       pString,
        PULONG                      pLength
    );

BOOLEAN
AnscAsn1NameIsNameEmpty
    (
        ANSC_HANDLE                 hThisObject
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_RDNSEQUENCE

 RDNSequence ::= SequenceOf RelativeDistinguishedName  {}

 **********************************************************************/

ANSC_STATUS
AnscAsn1RDNSequenceIsChildValid
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hChild
    );

ANSC_HANDLE
AnscAsn1RDNSequenceCreateChild
    (
        ANSC_HANDLE                 hThisObject,
        BOOLEAN                     bAddItIn
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_ATTRIBUTE

 Attribute ::= Sequence 
     {
                     attributeType OID 
                             value AttributeValues 
     }

 **********************************************************************/

PANSC_ATTR_OBJECT
AnscAsn1AttributeCreateChildAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PCHAR
AnscAsn1AttributeGetChildName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

ANSC_HANDLE
AnscAsn1AttributeCreateChildObject
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

/*
 *  Manually added functions
 */
BOOLEAN
AnscAsn1AttributeSetTypeAndStringValue
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString,
        PCHAR                       pValue,
        ULONG                       ulOfValue
    );

BOOLEAN
AnscAsn1AttributeSetTypeAndHandle
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString,
        ANSC_HANDLE                 hValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_RELATIVEDISTINGUISHEDNAME

 RelativeDistinguishedName ::= SetOf AttributeTypeAndValue  {}

 **********************************************************************/

ANSC_STATUS
AnscAsn1RelativeDistinguishedNameIsChildValid
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hChild
    );

ANSC_HANDLE
AnscAsn1RelativeDistinguishedNameCreateChild
    (
        ANSC_HANDLE                 hThisObject,
        BOOLEAN                     bAddItIn
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_ATTRIBUTETYPEANDVALUE

 AttributeTypeAndValue ::= Sequence 
     {
                     attributeType OID 
                             value AttributeValue 
     }

 **********************************************************************/

PANSC_ATTR_OBJECT
AnscAsn1AttributeTypeAndValueCreateChildAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PCHAR
AnscAsn1AttributeTypeAndValueGetChildName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

ANSC_HANDLE
AnscAsn1AttributeTypeAndValueCreateChildObject
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

/*
 *  Manually added functions
 */
BOOLEAN
AnscAsn1AttrTypeAndValueSetTypeAndStringValue
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString,
        PCHAR                       pValue,
        ULONG                       ulOfValue
    );

BOOLEAN
AnscAsn1AttrTypeAndValueSetTypeAndHandle
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString,
        ANSC_HANDLE                 hVlaue
    );

BOOLEAN
AnscAsn1AttrTypeAndValueExportToString
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pString,
        PULONG                      pLength
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_ATTRIBUTEVALUES

 AttributeValues ::= SetOf AttributeValue  {}

 **********************************************************************/

ANSC_STATUS
AnscAsn1AttributeValuesIsChildValid
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hChild
    );

ANSC_HANDLE
AnscAsn1AttributeValuesCreateChild
    (
        ANSC_HANDLE                 hThisObject,
        BOOLEAN                     bAddItIn
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_ATTRIBUTEVALUE

 AttributeValue ::= Choice 
     {
                   x520dnQualifier PrintableString 
                       countryName PrintableString 
                 pkcs9EmailAddress IA5String 
                       contentType ContentType 
                  unstructuredName UnstructuredName 
                     messageDigest MessageDigest 
                       signingTime SigningTime 
                 challengePassword ChllengePassword 
               unstructuredAddress UnstructuredAddress 
                         bmpString BMPString 
                          x520Name X520name 
                    x520CommonName X520CommonName 
                        signerInfo SignerInfo 
                   pkcs9LocalKeyID OctetString 
                          keyUsage BitString 
                        utf8String UTF8String 
                      genderString PrintableString 
              printableCountryName PrintableString 
                      localityName X520LocalityName 
                   domainComponent DirectoryString 
                         t61String TeletexString 
                        extensions Extensions 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1AttributeValueCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1AttributeValueCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1AttributeValueGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

LONG
AnscAsn1AttributeValueGetChoiceByOID
    (
        ANSC_HANDLE                 hThisObject,
        PCHAR                       pOIDString
    );

PCHAR
AnscAsn1AttributeValueGetOIDValueByMask
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_X520NAME

 X520name ::= Choice 
     {
                     teletexString TeletexString 
                   printableString PrintableString 
                   universalString UniversalString 
                        utf8String UTF8String 
                         bmpString BMPString 
                       octetString OctetString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1X520nameCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1X520nameCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1X520nameGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1X520nameGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_UNSTRUCTUREDNAME

 UnstructuredName ::= Choice 
     {
                         iA5String IA5String 
                   universalString UniversalString 
                   printableString PrintableString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1UnstructuredNameCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1UnstructuredNameCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1UnstructuredNameGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1UnstructuredNameGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_DIRECTORYSTRING

 DirectoryString ::= Choice 
     {
                     teletexString TeletexString 
                   printableString PrintableString 
                   universalString UniversalString 
                        utf8String UTF8String 
                         bmpString BMPString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1DirectoryStringCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1DirectoryStringCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1DirectoryStringGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1DirectoryStringGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_MESSAGEDIGEST

 MessageDigest ::= OctetString 

 **********************************************************************/

 /* No internal function is required for this object. */    

/**********************************************************************

 OBJECT -- ANSC_ASN1_SIGNINGTIME

 SigningTime ::= Time 

 **********************************************************************/

 /* No internal function is required for this object. */    

/**********************************************************************

 OBJECT -- ANSC_ASN1_CHLLENGEPASSWORD

 ChllengePassword ::= Choice 
     {
                   printableString PrintableString 
                         t61String TeletexString 
                   universalString UniversalString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1ChllengePasswordCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1ChllengePasswordCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1ChllengePasswordGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1ChllengePasswordGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_UNSTRUCTUREDADDRESS

 UnstructuredAddress ::= Choice 
     {
                   printableString PrintableString 
                         t61String TeletexString 
                   universalString UniversalString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1UnstructuredAddressCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1UnstructuredAddressCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1UnstructuredAddressGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1UnstructuredAddressGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_CONTENTTYPE

 ContentType ::= OID 

 **********************************************************************/

 /* No internal function is required for this object. */    

/**********************************************************************

 OBJECT -- ANSC_ASN1_X520COMMONNAME

 X520CommonName ::= Choice 
     {
                     teletexString TeletexString 
                   printableString PrintableString 
                   universalString UniversalString 
                        utf8String UTF8String 
                         bmpString BMPString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1X520CommonNameCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1X520CommonNameCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1X520CommonNameGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1X520CommonNameGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );

/**********************************************************************

 OBJECT -- ANSC_ASN1_X520LOCALITYNAME

 X520LocalityName ::= Choice 
     {
                     teletexString TeletexString 
                   printableString PrintableString 
                   universalString UniversalString 
                        utf8String UTF8String 
                         bmpString BMPString 
     }

 **********************************************************************/

ANSC_HANDLE
AnscAsn1X520LocalityNameCreateSelection
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       index
    );

PANSC_ATTR_OBJECT
AnscAsn1X520LocalityNameCreateSelectionAttr
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

PCHAR
AnscAsn1X520LocalityNameGetSelectionName
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       selType
    );

BOOLEAN
AnscAsn1X520LocalityNameGetChoiceTagValue
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       uIndex,
        PASN_OBJECT_FORM_TYPE       pAttr,
        PULONG                      pTagValue
    );


#endif  /*_ANSC_ASN1_NAME_INTERNAL_H*/

