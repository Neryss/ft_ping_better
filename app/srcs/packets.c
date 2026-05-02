/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:31:40 by ckurt             #+#    #+#             */
/*   Updated: 2026/05/02 18:56:13 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packets.h"
#include "ft_ping.h"
#include "network.h"
#include "stats.h"
#include <bits/time.h>
#include <netinet/ip_icmp.h>
#include <strings.h>
#include <stdio.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

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

/*
* TODO: we should get ID as BE not LE (?) and display it when using -v
*		on the first line
*/
t_packet	create_packet(int packet_size, int *seq)
{
	int			i;
	t_packet	packet;

	i = -1;
	bzero(&packet, sizeof(t_packet));
	packet.header.type = ICMP_ECHO;
	packet.header.code = 0;
	packet.header.un.echo.id = getpid();
	packet.header.un.echo.sequence = (*seq)++;
	while (i++ < packet_size)
		packet.payload[i] = i + '0';
	packet.header.checksum = 0;
	packet.header.checksum = checksum(&packet,
			sizeof(struct icmphdr) + packet_size);
	return (packet);
}

void	send_packet(t_ping *ping)
{
	t_packet	pckt;

	pckt = create_packet(ping->flags.packet_size, &ping->seq);
	if (sendto(ping->socket, &pckt,
			sizeof(struct icmphdr) + ping->flags.packet_size, 0,
			ping->dest->ai_addr, sizeof(struct sockaddr)) == -1)
		perror("could not send packet!");
	else
		ping->packets_stats.sent++;
	clock_gettime(CLOCK_MONOTONIC, &ping->start);
}

int	check_rcv_error(char *buffer, t_ping *ping)
{
	struct ip		*ip_header;
	struct icmphdr	*icmp_header;

	ip_header = (struct ip *)buffer;
	icmp_header = (struct icmphdr *)((char *)buffer + (ip_header->ip_hl * 4));
	if (icmp_header->type == 0)
		return (0);
	if (icmp_header->type == 11)
	{
		if (ping->flags.verbose)
			printf("time to live exceeded\n");
	}
	else if (icmp_header->type == 3)
		if (ping->flags.verbose)
			printf("Destination unreachable\n");
	return (1);
}

void	rcv_packet(t_ping *ping)
{
	char				buffer[MAX_PAYLOAD_SIZE];
	int					ret;

	ret = recv(ping->socket, &buffer, sizeof(buffer), 0);
	if (ret >= 0)
	{
		if (!check_rcv_error(buffer, ping))
		{
			clock_gettime(CLOCK_MONOTONIC, &ping->end);
			print_rcv_ping(ping, ret, buffer);
			ping->packets_stats.rcv++;
			calculate_rtt_stats(ping);
		}
	}
	else
	{
		if (ping->flags.verbose)
			perror("receive packet failed\n");
	}
}
