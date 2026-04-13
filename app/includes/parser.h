/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:10:19 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 21:38:06 by ckurt            ###   ########.fr       */
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
# include "errors.h"
# include "parser_utils.h"

void	parse_args(int argc, char **argv, t_flags *flags);
char    *get_identifier(char *arg);
int     check_identifier(char *id, char *value, t_flags *flags);


#endif
