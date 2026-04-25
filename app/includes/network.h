/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:58:40 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:08:50 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_H
# define NETWORK_H
# include "ft_ping.h"

void	dns_lookup(t_ping *ping);
void	reverse_dns_lookup(t_ping *ping);
void	print_rcv_ping(t_ping *ping, int bytes, char *buffer);

#endif
