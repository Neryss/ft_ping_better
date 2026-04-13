/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:02:16 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:21:17 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "flags.h"
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "parser_utils.h"

int	store_int_flag(char *value, int *var)
{
	if (!is_numeric(value))
	{
		*var = atoi(value);
		printf("Found value and stored it in flags: %d\n", *var);
		return (0);
	}
	printf("Error: wrong format\n");
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
		{
			printf("error impossible value\n");
			return (1);
		}
		*var = tmp;
		printf("Found value and stored it in flags: %d\n", *var);
		return (0);
	}
	printf("Error: wrong format\n");
	return (1);
}

int	check_identifier(char *id, char *value, t_flags *flags)
{
	if (!id)
		error_exit(3, "invalid option -- %s", id);
	if (*id == 'c')
		store_int_flag(value, &flags->count);
	else if (*id == 'w')
		store_int_flag(value, &flags->deadline);
	else if (*id == 's')
		store_int_flag(value, &flags->packet_size);
	else if (*id == 'i')
	{
		if (!is_float(value))
			flags->interval = atof(value);
		else
			error_exit(1, "invalid value %f", flags->interval);
	}
	else if (!strcmp(id, "ttl"))
	{
		store_uint8_flag(value, &flags->ttl);
		printf("uint: %d\n", flags->ttl);
	}
	else
		error_exit(1, "invalid option %s", id);
	return (0);
}

void	handle_dashes(int argc, char **argv, int i, t_flags *flags)
{
	char	*identifier;

	identifier = NULL;
	identifier = get_identifier(argv[i]);
	if (!identifier)
		error_exit(2, "no arguments provided");
	is_non_arg_flag(identifier);
	if (i != argc - 1)
		check_identifier(identifier, argv[i + 1], flags);
	else
		error_exit(2, "no argument provided");
}

void	parse_args(int argc, char **argv, t_ping *ping)
{
	int		i;

	i = -1;
	if (argc < 2)
		error_exit(2, "no arguments provided");
	else
	{
		while (i++ < argc - 1)
		{
			if (argv[i][0] == '-')
			{
				handle_dashes(argc, argv, i, &ping->flags);
				i++;
			}
			else
			{
				ping->target = argv[i];
				printf("target is: %s\n", ping->target);
			}
		}
	}
}
