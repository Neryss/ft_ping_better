/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:47:44 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/27 16:51:14 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_floats.h"
#include "errors.h"
#include "parser_utils.h"

void	parse_i_float(char *pass, t_flags *flags)
{
	if (!is_float(pass))
		flags->interval = atof(pass);
	else
		error_exit(1, false, "invalid value %f", flags->interval);
}
