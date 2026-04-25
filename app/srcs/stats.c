/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:27:36 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/25 19:20:06 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stats.h"
#include "ft_ping.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

static long double	calculate_stddev(t_ping *ping)
{
	long double	mean;
	long double	smean;
	long double	stddev;

	mean = ping->packets_stats.avg / ping->packets_stats.rcv;
	smean = ping->packets_stats.sqrd / ping->packets_stats.rcv;
	stddev = sqrt(smean - (mean * mean));
	return (stddev);
}

void	print_stats(t_ping *ping)
{
	double		loss;
	long double	avg;
	long double	stddev;

	avg = ping->packets_stats.avg / ping->packets_stats.sent;
	stddev = calculate_stddev(ping);
	clock_gettime(CLOCK_MONOTONIC, &ping->program_end);
	printf("--- %s statistics ---\n", ping->argv_target);
	loss = (double)(ping->packets_stats.sent - ping->packets_stats.rcv)
		/ (double)ping->packets_stats.sent * 100.0;
	printf("%d packets transmitted, %d packets received, %.0f%% packet loss\n",
		ping->packets_stats.sent, ping->packets_stats.rcv,
		(loss));
	printf("round-trip min/avg/max/stddev = %.3Lf/%.3Lf/%.3Lf/%.3Lf ms\n",
		ping->packets_stats.min / 1000.0, avg / 1000.0,
		ping->packets_stats.max / 1000.0, stddev / 1000.0);
}

void	calculate_rtt_stats(t_ping *ping)
{
	long double	rtt;

	rtt = (double)((ping->end.tv_nsec - ping->start.tv_nsec) / 1000000.0);
	rtt += ping->end.tv_sec - ping->start.tv_sec;
	rtt *= 1000.0;
	if (rtt > ping->packets_stats.max)
		ping->packets_stats.max = rtt;
	if (rtt < ping->packets_stats.min || ping->packets_stats.min == 0.0)
		ping->packets_stats.min = rtt;
	ping->packets_stats.rtt = rtt;
	ping->packets_stats.avg += rtt;
	ping->packets_stats.sqrd += rtt * rtt;
}
