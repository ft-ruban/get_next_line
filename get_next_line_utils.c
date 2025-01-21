/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:10:16 by ldevoude          #+#    #+#             */
/*   Updated: 2025/01/16 15:10:19 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	return_val;

	if (size == 0)
		return (ft_strlen(src));
	return_val = 0;
	while (--size > 0 && src[return_val] != '\0')
	{
		dst[return_val] = src[return_val];
		return_val++;
	}
	dst[return_val] = '\0';
	while (src[return_val] != '\0')
		return_val++;
	return (return_val);
}
