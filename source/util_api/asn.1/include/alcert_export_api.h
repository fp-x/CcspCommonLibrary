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

    MODULE: alcert_export_api.h

        ASN.1 ANSC Code Generated by Cisco Systems, Inc.

    ---------------------------------------------------------------

    COPYRIGHT:

        Cisco Systems, Inc., 1999 ~ 2003

        All Rights Reserved.

    ---------------------------------------------------------------

    DESCRIPTION:

        This interface is for the ALCert implementation.

    ---------------------------------------------------------------

    ENVIRONMENT:

        platform independent

    ---------------------------------------------------------------

    AUTHOR:

        Bin Zhu

    ---------------------------------------------------------------

    REVISION HISTORY:

        *   09/15/2002  initial revision

 **********************************************************************/


#ifndef  _ALCERT_EXPORT_API_H
#define  _ALCERT_EXPORT_API_H

ANSC_HANDLE
AnscCreateALCert
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hReserved
    );

ANSC_STATUS
AnscRemoveALCert
    (
        ANSC_HANDLE                 hCertContext
    );


#endif  /*_ALCERT_EXPORT_API_H*/


