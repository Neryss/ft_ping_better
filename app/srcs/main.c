/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:13:02 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/18 19:33:17 by ckurt            ###   ########.fr       */
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

t_ping	g_ping;

int	main(int argc, char **argv)
{
	bzero(&g_ping, sizeof(g_ping));
	clock_gettime(CLOCK_MONOTONIC, &g_ping.program_start);
	if (getuid())
		error_exit(1, "you need sudo for raw sockets creation\n");
	setup_signals();
	g_ping.sleep_time = 1;
	init_flags(&g_ping.flags);
	parse_args(argc, argv, &g_ping);
	print_flags(&g_ping.flags);
	dns_lookup(&g_ping);
	reverse_dns_lookup(&g_ping);
	init_socket(&g_ping);
	ping_loop(&g_ping);
	return (0);
}
