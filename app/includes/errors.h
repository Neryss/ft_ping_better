/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:45:47 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 21:28:43 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# define ERROR_PRINT "ft_ping: %s\nTry \'ft_ping -?\' for more information.\n"

void    error_exit(int code, const char *msg, ...);

#endif