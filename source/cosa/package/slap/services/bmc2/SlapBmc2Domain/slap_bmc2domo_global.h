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

    module:	slap_bmc2domo_global.h

        For Service Logic Aggregation Plane Implementation (SLAP),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file includes all the header files required by
        the Slap Bmc2 Domain implementation.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        06/29/05    initial revision.

**********************************************************************/


#ifndef  _SLAP_BMC2DOMO_GLOBAL_
#define  _SLAP_BMC2DOMO_GLOBAL_


#include "ansc_platform.h"
#include "ansc_ato_interface.h"
#include "ansc_ato_external_api.h"

#include "slap_co_oid.h"
#include "slap_co_name.h"
#include "slap_co_type.h"

#include "slap_properties.h"
#include "slap_ifo_goa.h"
#include "slap_ifo_uoa.h"
#include "slap_ifo_ola.h"

#include "slap_bmc2domo_interface.h"
#include "slap_bmc2domo_exported_api.h"
#include "slap_bmc2domo_internal_api.h"

#include "bmc2_co_oid.h"
#include "bmc2_co_name.h"
#include "bmc2_co_type.h"
#include "bmc2_properties.h"

#include "bmc2_envco_interface.h"
#include "bmc2_envco_exported_api.h"
#include "bmc2_comeo_interface.h"
#include "bmc2_comeo_exported_api.h"
#include "bmc2_comto_interface.h"
#include "bmc2_comto_exported_api.h"
#include "bmc2_comdo_interface.h"
#include "bmc2_comdo_exported_api.h"
#include "bmc2_reqco_interface.h"
#include "bmc2_reqco_exported_api.h"

#include "dslg_cli_cmdlist.h"

#endif
