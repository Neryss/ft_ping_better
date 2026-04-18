/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:31:40 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 20:18:17 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packets.h"
#include "ft_ping.h"
#include <strings.h>

unsigned short	checksum(void *b, int len)
{
	unsigned short	*buf;
	unsigned int	sum;
	unsigned short	result;

	buf = b;
	sum = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char *)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return (result);
}

t_packet	create_packet(int packet_size)
{
	static int	seq;
	int			i;
	t_packet	packet;

	i = 0;
	seq = 0;
	bzero(&packet, sizeof(t_packet));
	packet.header.type = ICMP_ECHO;
	packet.header.code = 0;
	packet.header.un.echo.id = getpid();
	packet.header.un.echo.sequence = seq++;
	while (i++ < packet_size)
		packet.payload[i] = i + '0';
	packet.header.checksum = 0;
	packet.header.checksum = checksum(&packet,
			packet_size + sizeof(struct icmphdr));
	return (packet);
}

void	send_packet(t_ping *ping)
{
	t_packet	packet;

	packet = create_packet(ping->flags.packet_size);
	(void) packet;
}
