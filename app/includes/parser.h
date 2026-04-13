/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:10:19 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/13 16:11:32 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_ping.h"
# include <stdbool.h>
# include <stdint.h>

void	parse_args(int argc, char **argv, t_ping *ping);
char	*get_identifier(char *arg);
int		check_identifier(char *id, char *value, t_flags *flags);
void	handle_dashes(int argc, char **argv, int i, t_flags *flags);

#endif
