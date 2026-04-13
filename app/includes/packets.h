/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 02:22:31 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:23:15 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKETS_H
# define PACKETS_H

# define MAX_PAYLOAD_SIZE 65399

# include <netinet/ip_icmp.h>
# include <unistd.h>
# include "ft_ping.h"

typedef struct s_packet
{
	struct icmphdr	header;
	char			payload[MAX_PAYLOAD_SIZE];
}				t_packet;

t_packet		create_packet(int packet_size);
void			send_packet(t_ping *ping);
unsigned short	checksum(void *b, int len);

#endif
