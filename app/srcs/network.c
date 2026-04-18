/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:00:29 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/18 21:01:55 by ckurt            ###   ########.fr       */
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
		error_exit(9, "unknown host");
	ping->dest = (struct addrinfo *)result;
	if (!inet_ntop(AF_INET,
			&(((struct sockaddr_in *)ping->dest->ai_addr)->sin_addr),
			ping->target, INET_ADDRSTRLEN))
		perror("Couldn't retreive from inet_ntop!");
	printf("dns target: %s\n", ping->target);
}

void	reverse_dns_lookup(t_ping *ping)
{
	struct sockaddr_in	tmp_addr;
	socklen_t			len;
	int					ret;

	tmp_addr.sin_family = AF_INET;
	tmp_addr.sin_addr.s_addr = inet_addr(ping->target);
	len = sizeof(struct sockaddr_in);
	ret = getnameinfo((struct sockaddr *)&tmp_addr, len,
			ping->dns, sizeof(ping->dns), NULL, 0,
			NI_NAMEREQD);
	if (ret)
		error_exit(10, "could not resolve reverse dns of %s: %s",
			ping->target, gai_strerror(ret));
	printf("reverse dns: %s", ping->dns);
}
