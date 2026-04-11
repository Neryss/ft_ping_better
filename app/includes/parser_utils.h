/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:10:12 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 21:42:08 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include <stdbool.h>
# include <ctype.h>
# include <stdio.h>

# define PING_VERSION "ft_ping 1.0\nMade by ckurt\n"
# define PING_HELP "Usage: ft_ping [OPTION...] HOST ...\n"\
"Send ICMP ECHO_REQUEST packets to network hosts.\n"\
"	Available options:\n"\
"	\n"\
"		-c NUMBER		stop after sending NUMBER packets\n"\
"		-w NUMBER		stop after NUMBER seconds\n"\
"		-i NUMBER		wait NUMBER of seconds between sending each packet\n"\
"		-s NUMBER		send NUMBER data octets\n"\
"		\n"\
"		-?				gives this help list\n"\
"		-v				prints program version\n"

bool	is_numeric(char *s);
bool    is_float(char *s);

#endif