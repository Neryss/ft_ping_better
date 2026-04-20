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
	struct timespec	end;
	(void)sig;
	g_ping.running = false;
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	// uint64_t delta_us = (end.tv_sec - g_ping.start.tv_sec) * 1000000 + (end.tv_nsec - g_ping.start.tv_nsec) / 1000;
	uint64_t	delta_us = (end.tv_sec - g_ping.start.tv_sec);
	printf("Program stopped after %ld\n", delta_us);
}

void	setup_signals(void)
{
	signal(SIGALRM, alarm_handler);
	signal(SIGINT, int_handler);
}
