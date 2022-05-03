/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:27 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 21:34:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	buf_init(t_buf *b, int fd)
{
	b->prev_fd = fd;
	b->cursor = NULL;
	b->rc = BUFFER_SIZE;
}

// DESCRIPTION
// 	Appends c to the str and returns it.
// 	Always new memory will be allocated and previous memory address
// 	will be freed.
static char	*append_realloc(char *str, char c)
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

char	*get_next_line(int fd)
{
	static t_buf	b = {{0}, NULL, 0, -1};
	char			*next_line;

	next_line = NULL;
	if (b.prev_fd != fd)
		buf_init(&b, fd);
	while (b.cursor || b.rc == BUFFER_SIZE)
	{
		if (b.cursor == NULL)
		{
			b.rc = read(fd, b.buf, BUFFER_SIZE);
			if (b.rc < 0)
				return (NULL);
			b.buf[b.rc] = '\0';
			b.cursor = b.buf;
		}
		while (*b.cursor)
		{
			next_line = append_realloc(next_line, *b.cursor);
			if (*b.cursor++ == '\n')
				return (next_line);
		}
		b.cursor = NULL;
	}
	return (next_line);
}
