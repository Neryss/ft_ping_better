/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:42:05 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/20 13:46:35 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packets_utils.h"
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>

void	dump_response(void *data)
{
	struct ip		*ip_header;
	struct icmphdr	*icmp_header;
	char			*payload;

	ip_header = (struct ip *)data;
	icmp_header = (struct icmphdr *)((char *)data + (ip_header->ip_hl * 4));
	payload = (char *)data + (ip_header->ip_hl * 4) + sizeof(struct icmphdr);
	printf("=== IP Header ===\n");
	printf("Version: %u\n", ip_header->ip_v);
	printf("Ip len: %u\n", ip_header->ip_hl * 4);
	printf("=== ICMP header ===\n");
	printf("Type: %u\n", icmp_header->type);
	printf("Code: %u\n", icmp_header->code);
	printf("checksum: %u\n", icmp_header->checksum);
	printf("payload: %s\n", payload);
	printf("ttl: %d\n", icmp_header->un.echo.sequence);
}
