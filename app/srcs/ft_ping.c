/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:13:10 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/18 19:30:39 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "packets.h"
#include <errors.h>
#include <asm-generic/socket.h>
#include <sys/socket.h>

void	init_socket(t_ping *ping)
{
	ping->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->socket < 0)
	{
		perror("could not create socket!");
		exit(15);
	}
}

void	set_raw_sockotp(t_ping *ping)
{
	struct timeval	tv_out;

	tv_out.tv_sec = ping->flags.timeout;
	tv_out.tv_usec = 0;
	if (setsockopt(ping->socket, SOL_IP,
			IP_TTL, &ping->flags.ttl,
			sizeof(ping->flags.ttl)))
	{
		perror("could not set sockopts timeout!");
		exit(1);
	}
	if (setsockopt(ping->socket, SOL_SOCKET,
			SO_RCVTIMEO, &tv_out, sizeof(tv_out)))
	{
		perror("could not set sockopts timeout!");
		exit(1);
	}
	printf("Set options without fail\n");
}

void	ping_loop(t_ping *ping)
{
	set_raw_sockotp(ping);
	ping->running = true;
	ping->send = true;
	while (ping->running)
	{
		if (ping->send)
		{
			send_packet(ping);
			rcv_packet(ping);
			alarm(ping->sleep_time);
		}
	}
}
