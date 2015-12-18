#######################################################################
#   Copyright [2014] [Cisco Systems, Inc.]
# 
#   Licensed under the Apache License, Version 2.0 (the \"License\");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
# 
#       http://www.apache.org/licenses/LICENSE-2.0
# 
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an \"AS IS\" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#######################################################################
mykill () {
    if ps aux | grep $1 | grep -v grep; then
        echo "killing $1"
        kill $(ps aux | grep $1 | grep -v grep | awk '{print $2}')
        sleep 1
    fi
}
# myexec pam CcspPandMSsp "$SubsysArgs"
myexec() {
    if [ -e ./$1 ]; then
        if $3; then; sleep $3; fi
        cd $1
        echo $2 $3
        $2 
        cd ..
    fi
}
if [ "$1" = "kill" ] || [ "$2" = "kill" ]; then
    echo Killing CCSP Daemons
    mykill ccspRecoveryManager
    mykill CcspTandDSsp
    mykill CcspDnsSsp
    mykill CcspFuSsp
    mykill CcspSsdSsp
    mykill CcspPandMSsp
    mykill CcspTr069PaSsp
    mykill PsmSsp
    mykill CcspRmSsp
    mykill CcspCrSsp
#    mykill CcspLmSsp
    mykill CcspMtaAgentSsp
    mykill CcspCMAgentSsp
    mykill CcspLMLite
    mykill CcspWecbController   
fi

# Start coredump
if [ -f "$PWD/core_compr" ]; then
        if ! [ -e "/var/core" ]; then
                mkdir -p /var/core/
        fi
        echo "|$PWD/core_compr /var/core %p %e" >/proc/sys/kernel/core_pattern
        ulimit -c unlimited

        ./core_report.sh &
fi

# Start Config Recover
echo "Starting Config Recover Daemon ..."
conf_rec &

cp ccsp_msg.cfg /tmp


if ps aux | grep dbus-daemon.*ccsp | grep -v grep; then
    echo "Starting dbus"
    # have IP address for dbus config generated
    #./DbusCfg
    if [ -e ./create_dbus_if.sh ]; then
        echo "./create_dbus_if.sh"
        ./create_dbus_if.sh
    fi
    dbus-daemon --config-file=./dbus-ccsp.conf --fork
fi

#touch cp_subsys_ert

Subsys="NA"
SubsysArgs=""

if [ -f ./cp_subsys_ert ]; then
    Subsys="eRT"
    SubsysArgs="-subsys eRT."
elif [ -e ./cp_subsys_emg ]; then
    Subsys="eMG"
    SubsysArgs="-subsys eMG."
fi

echo "Elected subsystem is $Subsys"

echo "CcspCrSsp $SubsysArgs"
CcspCrSsp $SubsysArgs

echo "PsmSsp $SubsysArgs"
PsmSsp $SubsysArgs

myexec pam "CcspPandMSsp $SubsysArgs" 1
# myexec pam "((sh ./email_notification_monitor.sh 12 &) &)" 
if [ -e ./pam ]; then
    cd ./pam
    ./email_notification_monitor.sh 12 &
    disown
    cd ..
fi

if [ -f ./cp_subsys_ert ]; then
    myexec rm "CcspRmSsp $SubsysArgs"
fi

if [ "x"$1 = "xpam" ] || [ "x"$2 = "xpam" ]; then
  exit 0
fi

myexec wecb "CcspWecbController $SubsysArgs" 5
myexec tr069pa "CcspTr069PaSsp $SubsysArgs" 5

if [ -e ./tr069pa ]; then
    # add firewall rule to allow incoming packet for port 7547
    sysevent setunique GeneralPurposeFirewallRule " -A INPUT -i erouter0 -p tcp --dport=7547 -j ACCEPT "
fi

myexec cm  "CcspCMAgentSsp $SubsysArgs" 5
myexec mta "CcspMtaAgentSsp $SubsysArgs" 30
myexec ssd "CcspSsdSsp $SubsysArgs" 1
myexec fu  "CcspFuSsp $SubsysArgs" 1
myexec tad "CcspTandDSsp $SubsysArgs" 3

sleep 1

if [ -e ./ccspRecoveryManager ]; then
    echo "./ccspRecoveryManager $SubsysArgs &"
    ./ccspRecoveryManager $SubsysArgs &
fi

myexec lm "CcspLMLite $SubsysArgs" 3

if [ -e ./lm ]; then
    cd lm
    sleep 5
    ./CcspLMLite &
fi
