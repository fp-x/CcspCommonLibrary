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

    module:	ansc_xsocket_state.c

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 1997 ~ 2002
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This module implements the advanced functions of the
        General Xsocket Object.

        *   AnscXsocketGetType
        *   AnscXsocketSetType
        *   AnscXsocketGetMode
        *   AnscXsocketSetMode
        *   AnscXsocketGetIpVersion
        *   AnscXsocketSetIpVersion
        *   AnscXsocketGetHostAddress
        *   AnscXsocketSetHostAddress
        *   AnscXsocketGetHostName
        *   AnscXsocketSetHostName
        *   AnscXsocketGetHostPort
        *   AnscXsocketSetHostPort
        *   AnscXsocketGetHostAddrInfo
        *   AnscXsocketSetHostAddrInfo
        *   AnscXsocketGetPeerAddress
        *   AnscXsocketSetPeerAddress
        *   AnscXsocketGetPeerName
        *   AnscXsocketSetPeerName
        *   AnscXsocketGetPeerPort
        *   AnscXsocketSetPeerPort
        *   AnscXsocketGetPeerAddrInfo
        *   AnscXsocketSetPeerAddrInfo
        *   AnscXsocketGetTransportType
        *   AnscXsocketSetTransportType
        *   AnscXsocketGetXsink
        *   AnscXsocketSetXsink

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Xuechen Yang

    ---------------------------------------------------------------

    revision:

        05/28/02    initial revision.

**********************************************************************/


#include "ansc_xsocket_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ULONG
        AnscXsocketGetType
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

ULONG
AnscXsocketGetType
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->Type;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetType
            (
                ANSC_HANDLE                 hThisObject,
                ULONG                       type
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ULONG                       type
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetType
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       type
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->Type = type;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ULONG
        AnscXsocketGetMode
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

ULONG
AnscXsocketGetMode
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->Mode;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetMode
            (
                ANSC_HANDLE                 hThisObject,
                ULONG                       mode
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ULONG                       mode
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetMode
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       mode
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->Mode = mode;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ULONG
        AnscXsocketGetIpProtocol
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

ULONG
AnscXsocketGetIpProtocol
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->IpProtocol;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetIpProtocol
            (
                ANSC_HANDLE                 hThisObject,
                ULONG                       ipprotocol
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ULONG                       mode
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetIpProtocol
    (
        ANSC_HANDLE                 hThisObject,
        ULONG                       ipprotocol
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->IpProtocol = ipprotocol;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        PUCHAR
        AnscXsocketGetHostAddress
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

PUCHAR
AnscXsocketGetHostAddress
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->HostAddress.Dot;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetHostAddress
            (
                ANSC_HANDLE                 hThisObject,
                PUCHAR                      address
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                PUCHAR                      address
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetHostAddress
    (
        ANSC_HANDLE                 hThisObject,
        PUCHAR                      address
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->HostAddress.Value = *(PULONG)address;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************
 *
 *     caller:     owner of this object
 *
 *     prototype:
 *
 *     PUCHAR
 *     AnscXsocketGetHostName
 *         (
 *             ANSC_HANDLE                 hThisObject
 *         );
 *
 *     description:
 *
 *     This function is called to retrieve the object state.
 *
 *     argument:   ANSC_HANDLE                 hThisObject
 *                 This handle is actually the pointer of this object
 *                 itself.
 *
 *     return:     object state.
 *
 ***********************************************************************/

PUCHAR
AnscXsocketGetHostName
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->HostName;
}


/**********************************************************************
 *
 *     caller:     owner of this object
 *
 *     prototype:
 *
 *     ANSC_STATUS
 *     AnscXsocketSetHostName
 *         (
 *             ANSC_HANDLE                 hThisObject,
 *             PUCHAR                      hostname
 *         );
 *
 *     description:
 *
 *     This function is called to configure the object state.
 *
 *     argument:   ANSC_HANDLE                 hThisObject
 *                 This handle is actually the pointer of this object
 *                 itself.
 *
 *                 PUCHAR                      address
 *                 Specifies the object state to be configured.
 *
 *     return:     status of operation.
 *
 ***********************************************************************/

ANSC_STATUS
AnscXsocketSetHostName
    (
        ANSC_HANDLE                 hThisObject,
        PUCHAR                      hostname
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    AnscCopyString(pMyObject->HostName, hostname);

    return  ANSC_STATUS_SUCCESS;
}

/**********************************************************************

    caller:     owner of this object

    prototype:

        USHORT
        AnscXsocketGetHostPort
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

USHORT
AnscXsocketGetHostPort
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->HostPort;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetHostPort
            (
                ANSC_HANDLE                 hThisObject,
                USHORT                      usPort
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                USHORT                      usPort
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetHostPort
    (
        ANSC_HANDLE                 hThisObject,
        USHORT                      usPort
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->HostPort = usPort;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        xskt_addrinfo*
        AnscXsocketGetHostAddrInfo
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

xskt_addrinfo*
AnscXsocketGetHostAddrInfo
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->pHostAddrInfo;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetHostAddrInfo
            (
                ANSC_HANDLE                 hThisObject,
                xskt_addrinfo*              pAddrInfo
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                USHORT                      usPort
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetHostAddrInfo
    (
        ANSC_HANDLE                 hThisObject,
        xskt_addrinfo*              pAddrInfo
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->pHostAddrInfo = pAddrInfo;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        PUCHAR
        AnscXsocketGetPeerAddress
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

PUCHAR
AnscXsocketGetPeerAddress
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->PeerAddress.Dot;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetPeerAddress
            (
                ANSC_HANDLE                 hThisObject,
                PUCHAR                      address
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                PUCHAR                      address
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetPeerAddress
    (
        ANSC_HANDLE                 hThisObject,
        PUCHAR                      address
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->PeerAddress.Value = *(PULONG)address;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************
 *
 *     caller:     owner of this object
 *
 *     prototype:
 *
 *     PUCHAR
 *     AnscXsocketGetPeerName
 *         (
 *             ANSC_HANDLE                 hThisObject
 *         );
 *
 *     description:
 *
 *     This function is called to retrieve the object state.
 *
 *     argument:   ANSC_HANDLE                 hThisObject
 *                 This handle is actually the pointer of this object
 *                 itself.
 *
 *     return:     object state.
 *
 ***********************************************************************/

PUCHAR
AnscXsocketGetPeerName
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->PeerName;
}


/**********************************************************************
 *
 *     caller:     owner of this object
 *
 *     prototype:
 *
 *     ANSC_STATUS
 *     AnscXsocketSetPeerName
 *         (
 *             ANSC_HANDLE                 hThisObject,
 *             PUCHAR                      peername
 *         );
 *
 *     description:
 *
 *     This function is called to configure the object state.
 *
 *     argument:   ANSC_HANDLE                 hThisObject
 *                 This handle is actually the pointer of this object
 *                 itself.
 *
 *                 PUCHAR                      address
 *                 Specifies the object state to be configured.
 *
 *     return:     status of operation.
 *
 ***********************************************************************/

ANSC_STATUS
AnscXsocketSetPeerName
    (
        ANSC_HANDLE                 hThisObject,
        PUCHAR                      peername
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    AnscCopyString(pMyObject->PeerName, peername);

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        USHORT
        AnscXsocketGetPeerPort
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

USHORT
AnscXsocketGetPeerPort
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->PeerPort;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetPeerPort
            (
                ANSC_HANDLE                 hThisObject,
                USHORT                      usPort
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                USHORT                      usPort
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetPeerPort
    (
        ANSC_HANDLE                 hThisObject,
        USHORT                      usPort
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->PeerPort = usPort;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        xskt_addrinfo*
        AnscXsocketGetPeerAddrInfo
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

xskt_addrinfo*
AnscXsocketGetPeerAddrInfo
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->pPeerAddrInfo;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetPeerAddrInfo
            (
                ANSC_HANDLE                 hThisObject,
                xskt_addrinfo*              pAddrInfo
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                USHORT                      usPort
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetPeerAddrInfo
    (
        ANSC_HANDLE                 hThisObject,
        xskt_addrinfo*              pAddrInfo
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->pPeerAddrInfo = pAddrInfo;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        UCHAR
        AnscXsocketGetTransportType
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

UCHAR
AnscXsocketGetTransportType
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->TransportType;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetTransportType
            (
                ANSC_HANDLE                 hThisObject,
                UCHAR                       transportType
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                UCHAR                       transportType
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetTransportType
    (
        ANSC_HANDLE                 hThisObject,
        UCHAR                       transportType
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->TransportType = transportType;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_HANDLE
        AnscXsocketGetXsink
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function retrieves the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     state of object.

**********************************************************************/

ANSC_HANDLE
AnscXsocketGetXsink
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    return  pMyObject->hXsinkObject;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        AnscXsocketSetXsink
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hXsink
            );

    description:

        This function configures the state of the object.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hXsink
                Specifies the state to be configured.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
AnscXsocketSetXsink
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hXsink
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PANSC_XSOCKET_OBJECT            pMyObject    = (PANSC_XSOCKET_OBJECT)hThisObject;
    PANSC_XSINK_OBJECT              pXsinkObject = (PANSC_XSINK_OBJECT  )pMyObject->hXsinkObject;

    pMyObject->hXsinkObject = hXsink;

    return  ANSC_STATUS_SUCCESS;
}
