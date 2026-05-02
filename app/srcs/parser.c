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

static int	handle_solo_id(char *id, t_flags *flags)
{
	printf("normalement je suis là\n");
	if (*id == '?')
	{
		printf("%s", PING_HELP);
		exit(0);
	}
	else if (*id == 'v')
	{
		printf("vevose detected\n");
		return (flags->verbose = true);
	}
	return (0);
}

int	check_identifier(int i, int argc, char *id, char *value, t_flags *flags)
{
	char	*pass;
	int		ret;

	if (strlen(id) > 1 && strcmp(id, "ttl"))
	{
		pass = &id[1];
		ret = 0;
	}
	else
	{
		pass = value;
		ret = 1;
	}
	if (handle_solo_id(id, flags))
		return(0);
	if (i == argc - 1 && ret)
		error_exit(1, "pas assez d'args mgl\n");
	if (*id == 'c')
		store_int_flag(pass, &flags->count);
	else if (*id == 'w')
		store_int_flag(pass, &flags->deadline);
	else if (*id == 's')
		store_int_flag(pass, &flags->packet_size);
	else if (*id == 'W')
		store_int_flag(pass, &flags->timeout);
	else if (*id == 'i')
		parse_i_float(pass, flags);
	else if (!strcmp(id, "ttl"))
		store_uint8_flag(pass, &flags->ttl);
	else
		error_exit(1, "invalid option %s", id);
	return (ret);
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
	return (check_identifier(i, argc, identifier, argv[i + 1], flags));
}

void	parse_args(int argc, char **argv, t_ping *ping)
{
	int		i;

	i = 0;
	if (argc < 2)
		error_exit(1, "missing host operand");
	else
	{
		while (i++ < argc - 1)
		{
			if (argv[i][0] == '-')
			{
				if (handle_dashes(argc, argv, i, &ping->flags))
					i++;
			}
			else
			{
				ping->target = argv[i];
				strcpy(ping->argv_target, argv[i]);
			}
		}
	}
	if (!ping->target)
		error_exit(1, "missing host operand");
}
