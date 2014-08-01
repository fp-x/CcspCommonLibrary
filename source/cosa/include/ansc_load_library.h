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

    module:	ansc_load_library.h

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco System  , Inc., 1997 ~ 2004
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This wrapper file defines all the platform-independent
        data structures and basic types related to DLL loadings.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Bin Zhu

    ---------------------------------------------------------------

    revision:

        06/17/03    initial revision.

**********************************************************************/


#ifndef  _ANSC_LOAD_LIBRARY_H
#define  _ANSC_LOAD_LIBRARY_H

#if (defined _ANSC_WINDOWSNT) || ( defined _ANSC_WINDOWS9X)

#define  AnscLoadLibrary                            LoadLibrary
#define  AnscFreeLibrary                            FreeLibrary
#define  AnscGetProcAddress                         GetProcAddress
#define  DLL_INSTANCE                               HINSTANCE
#define  ANSC_CALLBACK                              CALLBACK

#endif  /* _ANSC_WINDOWSNT | _ANSC_WINDOWS9X */

#if defined(_ANSC_LINUX)

#include <dlfcn.h>
#define  AnscLoadLibrary(f)                         dlopen(f,RTLD_NOW)
#define  AnscFreeLibrary                            dlclose
#define  AnscGetProcAddress                         dlsym
#define  DLL_INSTANCE                               PVOID
#define  ANSC_CALLBACK

#endif  /* _ANSC_LINUX */

#endif /* _ANSC_LOAD_LIBRARY_H */
