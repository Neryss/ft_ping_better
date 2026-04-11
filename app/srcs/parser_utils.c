/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:11:36 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 21:38:41 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"

bool	is_numeric(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

bool	is_float(char *s)
{
	int	dot_count;

	dot_count = 0;
	while (*s)
	{
		if (*s == '.')
		{
			if (dot_count < 1)
				dot_count++;
			else
			{
				printf("more than one dot\n");
				return (1);
			}
		}
		else if (!isdigit(*s))
		{
			printf("Not a digit: %c\n", *s);
			return (1);
		}
		s++;
	}
	return (0);
}
