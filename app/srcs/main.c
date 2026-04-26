/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:13:02 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/25 18:18:47 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "parser.h"
#include "network.h"
#include "errors.h"
#include "signals.h"
#include <unistd.h>
#include <strings.h>
#include <time.h>
#include "stats.h"

bool	g_running;

int	main(int argc, char **argv)
{
	t_ping	ping;

	bzero(&ping, sizeof(ping));
	ping.pid = getpid();
	clock_gettime(CLOCK_MONOTONIC, &ping.program_start);
	if (getuid())
		error_exit(1,
			"you need root permission for raw sockets creation\n");
	setup_signals();
	ping.sleep_time = 1;
	init_flags(&ping.flags);
	parse_args(argc, argv, &ping);
	print_flags(&ping.flags);
	dns_lookup(&ping);
	reverse_dns_lookup(&ping);
	init_socket(&ping);
	ping_loop(&ping);
	print_stats(&ping);
	return (0);
}
