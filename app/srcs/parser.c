/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:02:16 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 17:11:23 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

bool    is_float(char *s)
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
			return(1);
		}
		s++;
	}
	return (0);
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

int	check_identifier(char id, char *value, t_flags *flags)
{
	if (id == 'c')
	{
		if (!is_numeric(value))
		{
			flags->count = atoi(value);
			printf("Found value and stored it in flags: %d\n", flags->count);
			return (0);
		}
		printf("Error: wrong format\n");
		return (1);
	}
	else if (id == 'i')
	{
		if (!is_float(value))
		{
			flags->interval = atof(value);
			printf("found valid float and stored it: %f\n", flags->interval);
		}
		else
			printf("Found wrong float value: %s\n", value);
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_flags *flags)
{
	int	i;
	(void)flags;

	i = 0;
	if (argc < 2)
		return (1);
	else
	{
		printf("argc: %d\n", argc);
		i = 0;
		while (i < argc)
		{
			printf("Arg: %s\n", argv[i]);
			if (argv[i][0] == '-')
			{
				char	*identifier;

				identifier = get_identifier(argv[i]);
				if (!identifier)
					return (1);
				printf("This is the id: %c\n", *identifier);
				if (i != argc - 1)
					check_identifier(*identifier, argv[i + 1], flags);
				else
				{
					printf("Error, not argument provided\n");
					return (1);
				}
			}
			i++;
		}
	}
	return (0);
}
