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

    module:	tls_cco_global.h

        For Transport Layer Security Implementation (TLS),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2003
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file includes all the header files required by
        the TLS Conn Controller implementation.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        05/26/03    initial revision.

**********************************************************************/


#ifndef  _TLS_CCO_GLOBAL_
#define  _TLS_CCO_GLOBAL_


#include "ansc_platform.h"
#include "ansc_crypto_interface.h"
#include "ansc_crypto_external_api.h"
#include "ansc_oco_interface.h"
#include "ansc_oco_external_api.h"
#include "ansc_tso_interface.h"
#include "ansc_tso_external_api.h"

#include "tls_co_oid.h"
#include "tls_co_name.h"
#include "tls_co_type.h"
#include "tls_definitions.h"
#include "tls_properties.h"

#include "tls_ifo_mec.h"
#include "tls_ifo_hsm.h"
#include "tls_ifo_tsa.h"

#include "tls_cco_interface.h"
#include "tls_cco_exported_api.h"
#include "tls_cco_internal_api.h"

#include "tls_rko_interface.h"
#include "tls_rko_exported_api.h"
#include "tls_rco_interface.h"
#include "tls_rco_exported_api.h"
#include "tls_hso_interface.h"
#include "tls_hso_exported_api.h"
#include "tls_aho_interface.h"
#include "tls_aho_exported_api.h"
#include "tls_cso_interface.h"
#include "tls_cso_exported_api.h"
#include "tls_aco_interface.h"
#include "tls_aco_exported_api.h"

#include "tls_hsoclient_interface.h"
#include "tls_hsoclient_exported_api.h"
#include "tls_hsoserver_interface.h"
#include "tls_hsoserver_exported_api.h"


#endif
