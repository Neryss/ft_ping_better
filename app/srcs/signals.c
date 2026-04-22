/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:59:52 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/18 20:59:54 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "ft_ping.h"
#include <signal.h>
#include <time.h>
#include <stdio.h>

void	alarm_handler(int sig)
{
	(void)sig;
	g_ping.send = true;
}

void	int_handler(int sig)
{
	double		elapsed;
	long double	total_time;

	(void)sig;
	g_ping.running = false;
	clock_gettime(CLOCK_MONOTONIC, &g_ping.program_end);
	elapsed = ((double)(g_ping.program_end.tv_nsec
				- g_ping.program_start.tv_nsec)) / 1000000.0;
	total_time = (g_ping.program_end.tv_sec - g_ping.program_start.tv_sec)
		* 1000.0 + elapsed;
	printf("Program stopped after %.0Lf ms\n", total_time);
}

void	setup_signals(void)
{
	signal(SIGALRM, alarm_handler);
	signal(SIGINT, int_handler);
}
