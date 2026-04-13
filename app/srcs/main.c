/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:13:02 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:19:22 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "flags.h"

int	main(int argc, char **argv)
{
	t_flags	flags;

	init_flags(&flags);
	parse_args(argc, argv, &flags);
	print_flags(&flags);
	return (0);
}
