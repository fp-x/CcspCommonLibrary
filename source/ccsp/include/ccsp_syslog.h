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

#ifndef _CCSP_SYSLOG_H_
#include <syslog.h>

#define CCSP_SYSTEM_LOG_FACILITY LOG_LOCAL5 
#define CCSP_EVENT_LOG_FACILITY LOG_LOCAL4

#define syslog_systemlog(MODULE_NAME, priority, format, args...) { \
    openlog("[" MODULE_NAME "]", LOG_PID, CCSP_SYSTEM_LOG_FACILITY); \
    syslog(priority, format, ## args); \
    closelog();\
} 

#define syslog_eventlog(MODULE_NAME, priority, format, args...) { \
    openlog("[" MODULE_NAME "]", LOG_PID, CCSP_EVENT_LOG_FACILITY); \
    syslog(priority, format, ## args); \
    closelog();\
} 

#endif

