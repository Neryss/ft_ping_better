/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:19:50 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:19:08 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdint.h>

typedef struct s_flags
{
	// --ttl
	uint8_t	ttl;
	// -c
	int		count;
	// -i
	float	interval;
	// -w
	int		deadline;
	// -s
	int		packet_size;
}			t_flags;

void	init_flags(t_flags *flags);
void	print_flags(t_flags *flags);

#endif
