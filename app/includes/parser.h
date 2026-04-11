/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:10:19 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 18:22:25 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <ctype.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include "flags.h"

bool	is_numeric(char *s);
bool    is_float(char *s);
int		parse_args(int argc, char **argv, t_flags *flags);
char    *get_identifier(char *arg);
int     check_identifier(char id, char *value, t_flags *flags);


#endif
