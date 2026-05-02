/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:13:10 by ckurt             #+#    #+#             */
/*   Updated: 2026/05/02 18:49:58 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "packets.h"
#include "signals.h"
#include "io_utils.h"
#include <errors.h>
#include <asm-generic/socket.h>
#include <sys/socket.h>
#include <time.h>

void	init_socket(t_ping *ping)
{
	ping->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->socket < 0)
	{
		perror("could not create socket!");
		exit(1);
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
}

static double	get_time_seconds(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + ts.tv_nsec / 1e9);
}

void	ping_loop(t_ping *ping)
{
	double	last_time;
	double	current_time;

	last_time = 0.0;
	current_time = 0.0;
	if (ping->flags.deadline)
		set_deadline_timer(ping->flags.deadline);
	set_raw_sockotp(ping);
	print_preamble(ping);
	while (g_running)
	{
		current_time = get_time_seconds();
		if (current_time - last_time >= ping->flags.interval
			|| last_time == 0.0)
		{
			last_time = current_time;
			send_packet(ping);
			rcv_packet(ping);
			if (ping->flags.count != 0 && ping->seq >= ping->flags.count)
				return ;
		}
	}
}
