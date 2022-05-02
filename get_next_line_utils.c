/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:35 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 21:37:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;

	if (dstsize == 0 || ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	if (ft_strlen(src) == 0)
		return (ft_strlen(dst));
	cnt = 0;
	while (*dst && cnt < dstsize - 1)
	{
		dst++;
		cnt++;
	}
	while (*src && cnt < dstsize - 1)
	{
		*dst = *src;
		dst++;
		src++;
		cnt++;
	}
	*dst = '\0';
	while (*src++)
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

char	*strcat_realloc(char *dst, char *src)
{
	char	*new;
	int		size;

	size = 1;
	if (dst)
		size += ft_strlen(dst);
	if (src)
		size += ft_strlen(src);
	new = malloc(sizeof(char) * size);
	new[0] = '\0';
	if (dst)
	{
		ft_strlcpy(new, dst, size);
		free(dst);
	}
	ft_strlcat(new, src, size);
	return (new);
}
