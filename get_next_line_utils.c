/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:35 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 19:21:23 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// str will be freed. And returns newly allocated memory address.
char	*append_realloc(char *str, char c)
{
	char	*new;
	int		size;

	size = 2;
	if (str)
		size += ft_strlen(str);
	new = malloc(size);
	if (str)
	{
		ft_strlcpy(new, str, size);
		free(str);
	}
	new[size - 2] = c;
	new[size - 1] = '\0';
	return (new);
}
