/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:37:43 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/18 21:02:19 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "flags.h"
# include <netdb.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_ping
{
	bool			running;
	bool			send;
	int				socket;
	t_flags			flags;
	char			*target;
	char			dns[NI_MAXHOST];
	struct addrinfo	*dest;
	struct timeval	start;
	struct timeval	end;
	int				sleep_time;
	int				seq;
}				t_ping;

extern t_ping	g_ping;

void	init_socket(t_ping *ping);
void	ping_loop(t_ping *ping);
void	set_raw_sockotp(t_ping *ping);

#endif
