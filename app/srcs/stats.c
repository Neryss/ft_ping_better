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

void	print_stats(t_ping *ping)
{
	double		elapsed;
	long double	total_time;
	long double	mdev;
	double		loss;

	clock_gettime(CLOCK_MONOTONIC, &ping->program_end);
	elapsed = ((double)(ping->program_end.tv_nsec
				- ping->program_start.tv_nsec)) / 1000000.0;
	total_time = (ping->program_end.tv_sec - ping->program_start.tv_sec)
		* 1000.0 + elapsed;
	printf("--- %s ping->statistics ---\n", ping->argv_target);
	loss = (double)(ping->packets_stats.sent - ping->packets_stats.rcv) / (double)ping->packets_stats.sent * 100.0;
	mdev = sqrt((ping->packets_stats.sqrd / ping->packets_stats.sent) - (ping->packets_stats.avg * ping->packets_stats.avg));
	printf("%d packets transmitted, %d packets received, %.0f%% packet loss\n",
		ping->packets_stats.sent, ping->packets_stats.rcv,
		(loss));
	printf("rtt min/avg/max/mdev = %.3Lf/%.3Lf/%.3Lf/%.3Lf ms\n", ping->packets_stats.min, ping->packets_stats.avg, ping->packets_stats.max, mdev);
	printf("Program stopped after %.0Lf ms\n", total_time);
}

void		calculate_rtt_stats(t_ping *ping)
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
	printf("RTT HERE: %Lf\n", ping->packets_stats.rtt);
	ping->packets_stats.avg += rtt;
	ping->packets_stats.sqrd += rtt * rtt;
}

