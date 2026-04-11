/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:13:02 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 17:17:42 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

int	main(int argc, char **argv)
{
	int	i;

	(void)argv;
	if (argc < 2)
		return (1);
	else
	{
		i = 0;
		while (i < argc)
		{
			printf("Arg: %s\n", argv[i]);
			if (!strcmp(argv[i], "-c"))
			{
			}
			i++;
		}
	}
	return (0);
}
