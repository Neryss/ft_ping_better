/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 02:22:31 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 02:23:20 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKETS_H
# define PACKETS_H

# define MAX_PAYLOAD_SIZE 65399

#include <sys/types.h>


typedef struct	s_packet
{
	struct icmphdr	header;
	char			payload[MAX_PAYLOAD_SIZE];
}				t_packet;

#endif
