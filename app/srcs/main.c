/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:13:02 by ckurt             #+#    #+#             */
/*   Updated: 2026/05/02 16:51:20 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "parser.h"
#include "network.h"
#include "signals.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include "stats.h"

bool	g_running;

int	main(int argc, char **argv)
{
	t_ping	ping;

	bzero(&ping, sizeof(ping));
	ping.pid = getpid();
	if (getuid())
	{
		printf("You need root permissions to create \
raw sockets, try with sudo\n");
		exit(1);
	}
	setup_signals();
	ping.sleep_time = 1;
	init_flags(&ping.flags);
	parse_args(argc, argv, &ping);
	dns_lookup(&ping);
	reverse_dns_lookup(&ping);
	init_socket(&ping);
	g_running = true;
	ping_loop(&ping);
	print_stats(&ping);
	return (0);
}
