/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:37:43 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/25 18:43:55 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "flags.h"
# include "stats.h"
# include "packets_stats.h"
# include <netdb.h>
# include <sys/time.h>
# include <stdbool.h>


typedef struct s_ping
{
	bool			running;
	int				socket;
	t_flags			flags;
	char			argv_target[NI_MAXHOST];
	char			*target;
	char			dns[NI_MAXHOST];
	struct addrinfo	*dest;
	struct timespec	program_start;
	struct timespec	program_end;
	struct timespec	start;
	struct timespec	end;
	int				sleep_time;
	int				seq;
	t_packet_stats	packets_stats;	
}				t_ping;

extern t_ping	g_ping;
extern bool		g_running;

void	init_socket(t_ping *ping);
void	ping_loop(t_ping *ping);
void	set_raw_sockotp(t_ping *ping);

#endif
