/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_flags.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:43:17 by ckurt             #+#    #+#             */
/*   Updated: 2026/05/02 16:44:13 by ckurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_FLAGS_H
# define STORE_FLAGS_H

# include <stdint.h>

int	store_int_flag(char *value, int *var);
int	store_uint8_flag(char *value, uint8_t *var);

#endif
