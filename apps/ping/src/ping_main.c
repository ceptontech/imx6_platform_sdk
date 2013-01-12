/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sdk.h"
#include "platform_init.h"
#include "enet/enet.h"
#include "iomux_config.h"
#include "timer/timer.h"
#include "ping.h"

#include "lwip/opt.h"
#include "lwip/init.h"
#include "lwip/raw.h"
#include "lwip/debug.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/sys.h"
#include "lwip/stats.h"
#include "lwip/ip.h"
#include "lwip/ip_frag.h"
#include "lwip/udp.h"
#include "lwip/snmp_msg.h"
#include "lwip/tcp_impl.h"
#include "lwip/dhcp.h"
#include "lwip/dns.h"
#include "lwip/autoip.h"

#define CLOCKTICKS_PER_MS (1)

struct netif netif;

ip_addr_t g_ping_target_addr;

extern err_t enet_init(struct netif *netif);
extern void enet_poll_for_packet(struct netif * netif);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void init_lwip(void)
{
    lwip_init();

	ip_addr_t addr, netmask, gw;
	IP4_ADDR(&addr, 192, 168, 10, 159);
	IP4_ADDR(&netmask, 255, 255, 255, 0);
	IP4_ADDR(&gw, 192, 168, 10, 200);

#if LWIP_NETIF_HOSTNAME
	netif.hostname = "lwip";
#endif

    netif_add(&netif, &addr, &netmask, &gw, NULL, enet_init, ethernet_input);
    netif_set_default(&netif);
    netif_set_up(&netif);

	if (1)
	{
		dhcp_start(&netif);
		dns_init();
	}
	// Auto IP
	else if (0)
	{
		autoip_start(&netif);
	}
	// Static IP address
	else
	{
		netif_set_up(&netif);
	}
	
	ping_init();

    printf("TCP/IP initialized.\n");
}

void run(void)
{
    uint32_t last_arp_time = 0;
    uint32_t last_time = 0;
    
    IP4_ADDR(&g_ping_target_addr, 10, 81, 4, 140);
    ping_send_to(&g_ping_target_addr);
    
    while (true)
    {
        // Poll for incoming packet.
        enet_poll_for_packet(&netif);

        // Call timers.
        if (sys_now() - last_arp_time >= ARP_TMR_INTERVAL * CLOCKTICKS_PER_MS)  
        {  
            etharp_tmr();  
            last_arp_time = sys_now();  
        }  
        if (sys_now() - last_time >= TCP_TMR_INTERVAL * CLOCKTICKS_PER_MS)
        {  
            tcp_tmr();  
            last_time = sys_now();  
        }      
    }
}

void main(void)
{
    platform_init();
    init_lwip();

    run();

    // Disable Ethernet.
//     imx_enet_stop(dev0);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////