/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:37:43 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 20:18:15 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "flags.h"
# include <netdb.h>
# include <sys/time.h>

typedef struct s_ping
{
	int				socket;
	t_flags			flags;
	char			*target;
	struct addrinfo	*dest;
	struct timeval	start;
	struct timeval	end;
}				t_ping;

void	init_socket(t_ping *ping);
void	ping_loop(t_ping *ping);

#endif
