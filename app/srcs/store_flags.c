/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:41:36 by ckurt             #+#    #+#             */
/*   Updated: 2026/05/02 16:44:28 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "store_flags.h"
#include "parser_utils.h"
#include "errors.h"

int	store_int_flag(char *value, int *var)
{
	if (!is_numeric(value))
	{
		*var = atoi(value);
		return (0);
	}
	error_exit(1, "invalid value (\'%s\' near \'%s\')",
		value, near_error(value));
	return (1);
}

int	store_uint8_flag(char *value, uint8_t *var)
{
	int	tmp;

	tmp = 0;
	if (!is_numeric(value))
	{
		tmp = atoi(value);
		if (tmp > 255 || tmp < 0)
			error_exit(1, "option value too big: %d\n", tmp);
		*var = tmp;
		return (0);
	}
	error_exit(1, "invalid value (\'%s\' near \'%s\')",
		value, near_error(value));
	return (1);
}
