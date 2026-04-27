/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:02:16 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/27 16:52:13 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "flags.h"
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "parser_utils.h"
#include "parse_floats.h"

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

int	check_identifier(char *id, char *value, t_flags *flags)
{
	char	*pass;

	if (strlen(id) > 1 && strcmp(id, "ttl"))
		pass = &id[1];
	else
		pass = value;
	if (*id == 'c')
		store_int_flag(pass, &flags->count);
	else if (*id == 'w')
		store_int_flag(pass, &flags->deadline);
	else if (*id == 's')
		store_int_flag(pass, &flags->packet_size);
	else if (*id == 'W')
		store_int_flag(pass, &flags->timeout);
	else if (*id == 'v')
		return (flags->verbose = true);
	else if (*id == 'i')
		parse_i_float(pass, flags);
	else if (!strcmp(id, "ttl"))
		store_uint8_flag(pass, &flags->ttl);
	else
		error_exit(1, "invalid option %s", id);
	return (0);
}

int	handle_dashes(int argc, char **argv, int i, t_flags *flags)
{
	char	*identifier;

	identifier = NULL;
	identifier = get_identifier(argv[i]);
	if (!identifier)
	{
		if (!strcmp(argv[i], "--"))
			return (1);
		error_exit(2, "option \"%s\" requires an argument", argv[i]);
	}
	if (i != argc - 1)
		check_identifier(identifier, argv[i + 1], flags);
	else
		error_exit(2, "option \"%s\" requires an argument", argv[i]);
	return (0);
}

void	parse_args(int argc, char **argv, t_ping *ping)
{
	int		i;

	i = 0;
	if (argc < 2)
		error_exit(1, "missing host operand");
	else
	{
		while (i++ < argc - 2)
		{
			if (argv[i][0] == '-')
				handle_dashes(argc, argv, i, &ping->flags);
		}
		ping->target = argv[i];
		strcpy(ping->argv_target, argv[i]);
	}
	if (!ping->target)
		error_exit(1, "missing host operand");
}
