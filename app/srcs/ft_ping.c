/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:13:10 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 20:20:20 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "errors.h"
#include <asm-generic/socket.h>
#include <sys/socket.h>

void	init_socket(t_ping *ping)
{
	ping->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->socket < 0)
		error_exit(15, "could not create socket\n");
	printf("Created socket\n");
}

void	ping_loop(t_ping *ping)
{
	struct timeval	tv_out;
	tv_out.tv_sec = ping->flags.timeout;
	tv_out.tv_usec = 0;

	// clock_gettime(CLOCK_MONOTONIC, )
	if (setsockopt(ping->socket, SOL_IP, IP_TTL, &ping->flags.ttl, sizeof(ping->flags.ttl)))
		error_exit(15, "could not set socket TTL\n");
	if (setsockopt(ping->socket, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out)))
		error_exit(15, "could not set socket timeout value\n");
	printf("Set options without fail\n");
}
