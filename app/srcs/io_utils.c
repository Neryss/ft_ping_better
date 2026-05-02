/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:45:41 by ckurt             #+#    #+#             */
/*   Updated: 2026/05/02 18:49:34 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_utils.h"
#include <stdio.h>

void	print_preamble(t_ping *ping)
{
	if (ping->flags.verbose)
		printf("PING %s (%s): %d data bytes, id 0x%04x = %d\n",
			ping->argv_target, ping->target,
			ping->flags.packet_size, ping->pid, ping->pid);
	else
		printf("PING %s (%s): %d data bytes\n",
			ping->argv_target, ping->target, ping->flags.packet_size);
}
