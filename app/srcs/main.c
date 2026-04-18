/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:13:02 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:19:22 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "parser.h"
#include "network.h"
#include "errors.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_ping	ping;

	if (getuid())
		error_exit(1, "you need sudo for raw sockets creation\n");
	init_flags(&ping.flags);
	parse_args(argc, argv, &ping);
	print_flags(&ping.flags);
	dns_lookup(&ping);
	reverse_dns_lookup(&ping);
	init_socket(&ping);
	ping_loop(&ping);
	return (0);
}
