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

void	alarm_handler(int sig)
{
	(void)sig;
	g_ping.send = true;
}

void	int_handler(int sig)
{
	(void)sig;
	g_ping.running = false;
}

void	setup_signals(void)
{
	signal(SIGALRM, alarm_handler);
	signal(SIGINT, int_handler);
}
