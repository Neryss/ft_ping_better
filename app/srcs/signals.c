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
#include <stdio.h>

void	int_handler(int sig)
{
	(void)sig;
	g_running = false;
}

static void	alarm_handler(int sig)
{
	(void)sig;
	g_running = false;
}

void	setup_signals(void)
{
	signal(SIGINT, int_handler);
	signal(SIGALRM, alarm_handler);
}

void	set_deadline_timer(int deadline)
{
	struct itimerval	it;

	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 0;
	it.it_value.tv_sec = deadline;
	it.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &it, NULL);
}
