/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:20:14 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 18:22:24 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

void	init_flags(t_flags *flags)
{
	flags->count = 0;
	flags->deadline = 0;
	flags->interval = 1.0f;
	flags->ttl = 64;
	flags->packet_size = 56;
}
