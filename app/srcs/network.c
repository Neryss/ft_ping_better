/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:00:29 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:08:47 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network.h"
#include "errors.h"
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

void	dns_lookup(t_ping *ping)
{
	struct addrinfo	hints;
	struct addrinfo	*result;

	bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(ping->target, NULL, &hints, &result) != 0)
		error_exit(9, "%s", "getaddrinfo failed");
	ping->dest = (struct addrinfo *)result;
	inet_ntop(AF_INET, &(((struct sockaddr_in *)ping->dest->ai_addr)->sin_addr),
		ping->target, INET_ADDRSTRLEN);
	printf("dns target: %s\n", ping->target);
}

void	reverse_dns_lookup(t_ping *ping)
{
	struct sockaddr_in	tmp_addr;
	socklen_t			len;
	char				buff[NI_MAXHOST];
	char				*ret;

	tmp_addr.sin_family = AF_INET;
	tmp_addr.sin_addr.s_addr = inet_addr(ping->target);
	len = sizeof(struct sockaddr_in);
	if (getnameinfo((struct sockaddr *)&tmp_addr, len,
			buff, sizeof(buff), NULL, 0,
			NI_NAMEREQD))
		error_exit(10, "could not resolve reverse dns of %s", ping->target);
	ret = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
	strcpy(ret, buff);
	if (!ret)
		error_exit(99, "Malloc failed during reverse dns");
	printf("reverse dns: %s", ret);
	free(ret);
}
