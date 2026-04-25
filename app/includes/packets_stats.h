/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets_stats.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:42:15 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/25 18:43:39 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKETS_STATS_H
# define PACKETS_STATS_H

#include <stdint.h>

typedef struct s_packets_stats
{
	uint32_t	sent;
	uint32_t	rcv;
	long double	min;
	long double	max;
	long double	avg;
	long double	rtt;
	long double	sqrd;
}				t_packet_stats;

#endif
