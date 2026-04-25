/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:17:14 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/25 18:48:40 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_H
# define STATS_H

struct s_ping;
typedef struct s_ping t_ping;

void	print_stats(t_ping *ping);
void	calculate_rtt_stats(t_ping *ping);

#endif
