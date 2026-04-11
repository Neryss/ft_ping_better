/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:46:43 by ckurt             #+#    #+#             */
/*   Updated: 2026/04/11 21:26:51 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	error_exit(int code, const char *msg, ...)
{
	va_list	args;
	int		len;
	char	*fmt_msg;

	va_start(args, msg);
	len = vsnprintf(NULL, 0, msg, args);
	va_end(args);
	if (len < 0)
		exit (67);
	fmt_msg = malloc(sizeof(char) * (len + 1));
	if (!fmt_msg)
		exit (68);
	va_start(args, msg);
	vsnprintf(fmt_msg, len + 1, msg, args);
	va_end(args);
	printf(ERROR_PRINT, fmt_msg);
	free(fmt_msg);
	exit(code);
}
