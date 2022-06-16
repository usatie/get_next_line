/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:27 by susami            #+#    #+#             */
/*   Updated: 2022/06/16 11:35:45 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

// SUCCESS	: returns (0)
// ERROR	: returns (-1)
static int	read_to_buf_if_needed(t_buf *b, int fd)
{
	if (b->cursor != NULL && *(b->cursor) != '\0')
		return (0);
	b->rc = read(fd, b->buf, BUFFER_SIZE);
	if (b->rc < 0)
		return (-1);
	b->buf[b->rc] = '\0';
	b->cursor = b->buf;
	return (0);
}

// ""				: returns (0)
// "\n"				: returns (1)
// "abcde"			: returns (5)
// "abcde\n12345"	: returns (6)
static size_t	len_to_cat(char *str)
{
	size_t	len;

	len = 0;
	while (*str && *str != '\n')
	{
		len++;
		str++;
	}
	if (*str == '\n')
		len++;
	return (len);
}

// 	s1 will always be freed even if on error.
static char	*strncat_reallocf(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	new_len;
	char	*new;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	new_len = s1_len + len_to_cat(s2) + 1;
	new = malloc(new_len);
	if (new == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	if (s1)
	{
		ft_strlcpy(new, s1, new_len);
		free(s1);
	}
	ft_strlcpy(new + s1_len, s2, len_to_cat(s2) + 1);
	return (new);
}

char	*get_next_line(int fd)
{
	static t_buf	b;
	char			*line;

	line = NULL;
	while (1)
	{
		if (read_to_buf_if_needed(&b, fd) < 0)
			return (NULL);
		else if (b.rc == 0)
			return (line);
		if (*b.cursor != '\0')
		{
			line = strncat_reallocf(line, b.cursor);
			if (line == NULL)
				return (NULL);
			b.cursor += len_to_cat(b.cursor);
			if (*(b.cursor - 1) == '\n')
				return (line);
		}
		b.cursor = NULL;
	}
}
