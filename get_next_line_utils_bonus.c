/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:38:40 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 21:38:42 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;

	if (dstsize == 0)
		return (ft_strlen(src));
	src_size = 0;
	while (*src)
	{
		if (src_size < dstsize - 1)
		{
			*dst = *src;
			dst++;
		}
		src++;
		src_size++;
	}
	*dst = '\0';
	return (src_size);
}
