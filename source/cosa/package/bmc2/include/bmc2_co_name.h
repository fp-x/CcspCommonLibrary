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

    module:	bmc2_co_name.h

        For Broadway Management Console v2.0 Implementation (BMC2),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2005
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines the object names for the Bmc2
        Component Objects.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        06/17/05    initial revision.

**********************************************************************/


#ifndef  _BMC2_CO_NAME_
#define  _BMC2_CO_NAME_


/***********************************************************
            GENERAL BMC2 FEATURE OBJECTS DEFINITION
***********************************************************/

/*
 * Define the object names for all the Feature Objects that cannot be categorized. Feature Objects
 * are the objects that encapsulate certain features and provide services.
 */
#define  BMC2_ENV_CONTROLLER_NAME                   "envController"
#define  BMC2_COM_EXECUTOR_NAME                     "comExecutor"
#define  BMC2_COM_TERMINAL_NAME                     "comTerminal"
#define  BMC2_COM_DOMAIN_NAME                       "comDomain"
#define  BMC2_REQ_CONTROLLER_NAME                   "reqController"


#endif
