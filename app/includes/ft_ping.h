/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:37:43 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:15:47 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "parser.h"
# include "flags.h"
# include <ctype.h>
# include <stdio.h>
# include <string.h>

typedef struct s_ping
{
	t_flags	flags;
}				t_ping;

#endif
