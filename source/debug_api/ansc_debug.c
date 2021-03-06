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

    module:	ansc_debug.c

        For CCSP trace related APIs

    ---------------------------------------------------------------

    copyright:

        Cisco Systems Inc., 2011 ~ 
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This API header file defines all the CCSP trace related
        functions.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Hui Ma

    ---------------------------------------------------------------

    revision:

        04/25/11    initial revision.

**********************************************************************/

/***********************************************************
       BASIC OPERATIONS BY MACROS AND INLINE FUNCTIONS
***********************************************************/
#include "ccsp_trace.h"
#include "user_time.h"
#include "ansc_time.h"
#include "ansc_debug.h"
#include <stdarg.h>

/**********************************************************************
                    VARIABLES FOR TRACE LEVEL
**********************************************************************/
INT  g_iTraceLevel = CCSP_TRACE_LEVEL_WARNING;
char *g_TraceLevelStr[] = {"EMERGENCY", "ALERT", "CRITICAL", "ERROR", "WARNING", "NOTICE", "INFO", "DEBUG"};
static void
AnscSetTraceLevel_ccsp
    (
        INT  traceLevel
    )
{
    g_iTraceLevel = traceLevel;
    if(g_iTraceLevel > CCSP_TRACE_LEVEL_DEBUG) g_iTraceLevel = CCSP_TRACE_LEVEL_DEBUG;
    else if(g_iTraceLevel < CCSP_TRACE_LEVEL_ALERT) g_iTraceLevel = CCSP_TRACE_LEVEL_ALERT;
}

static void
AnscSetTraceLevel_ansc
    (
        INT  traceLevel
    )
{
    int ansc_level = 0;
    ANSC_TRACE_ID_CFG          IdCfg     = {0};

    if(traceLevel > CCSP_TRACE_LEVEL_DEBUG) traceLevel = CCSP_TRACE_LEVEL_DEBUG;
    else if(traceLevel < CCSP_TRACE_LEVEL_ALERT) traceLevel = CCSP_TRACE_LEVEL_ALERT;
    
    switch(traceLevel)
    {
    case CCSP_TRACE_LEVEL_EMERGENCY:
        ansc_level = ANSC_TRACE_LEVEL_DEATH;
        break;
    case CCSP_TRACE_LEVEL_ALERT:
    case CCSP_TRACE_LEVEL_CRITICAL:
        ansc_level = ANSC_TRACE_LEVEL_CRITICAL;
        break;
    case CCSP_TRACE_LEVEL_ERROR:
        ansc_level = ANSC_TRACE_LEVEL_ERROR;
        break;
    case CCSP_TRACE_LEVEL_WARNING:
        ansc_level = ANSC_TRACE_LEVEL_WARNING;
        break;
    case CCSP_TRACE_LEVEL_NOTICE:
        ansc_level = ANSC_TRACE_LEVEL_TEST;
        break;
    case CCSP_TRACE_LEVEL_INFO:
        ansc_level = ANSC_TRACE_LEVEL_FLOW; /*for AnscTrace(), this macro compares with ANSC_TRACE_LEVEL_FLOW*/
        break;
    case CCSP_TRACE_LEVEL_DEBUG:
        ansc_level = ANSC_TRACE_LEVEL_VERBOSE;
        break;
    default:
        ansc_level = ANSC_TRACE_INVALID_LEVEL;
    }

    AnscTraceSetAllIdcfgLevels(ansc_level);
}

void
AnscSetTraceLevel
    (
        INT  traceLevel
    )
{
    AnscSetTraceLevel_ccsp(traceLevel);    
    AnscSetTraceLevel_ansc(traceLevel);    
}

