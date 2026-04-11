/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:02:16 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 22:00:54 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

static void is_non_arg_flag(char *id)
{
	if (*id == '?')
	{
		printf("%s", PING_HELP);
		exit(0);
	}
	else if (*id == 'v')
	{
		printf("%s", PING_VERSION);
		exit(0);
	}
}

int	parse_args(int argc, char **argv, t_flags *flags)
{
	int		i;
	char	*identifier;

	i = 0;
	identifier = NULL;
	if (argc < 2)
		return (1);
	else
	{
		i = 0;
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				identifier = get_identifier(argv[i]);
				if (!identifier)
					error_exit(3, "invalid option -- %s", identifier);
				is_non_arg_flag(identifier);
				if (i != argc - 1)
					check_identifier(identifier, argv[i + 1], flags);
				else
					error_exit(2, "no argument provided");
			}
			i++;
		}
	}
	return (0);
}
