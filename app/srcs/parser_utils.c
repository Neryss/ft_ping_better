/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:11:36 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/18 21:05:49 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"

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

void	is_non_arg_flag(char *id)
{
	if (*id == '?')
		error_exit(0, "%s", PING_HELP);
	else if (*id == 'V')
		error_exit(0, "%s", PING_VERSION);
	else if (*id == 'i' || *id == 's' || *id == 'c'
		|| *id == 'w' || *id == 'W'
		|| !strcmp(id, "ttl"))
		return ;
	error_exit(3, "argument doesn\'t exist");
}

char	*get_identifier(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] == '-')
		{
			count++;
			i++;
		}
		else
		{
			if (count > 2)
			{
				printf("Error, more than 2 dashes\n");
				return (NULL);
			}
			return (&arg[i]);
		}
	}
	return (NULL);
}

char	*near_error(char * value)
{
	int	i;

	i = 0;
	while(value[i])
	{
		if (value[i] == '.')
			return (value + i);
		if (!isdigit(value[i]))
			return (value);
		i++;
	}
	return (value);
}
