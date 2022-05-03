/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:27 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 21:14:55 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

typedef struct s_buf
{
	char	buf[BUFFER_SIZE + 1];
	char	*cursor;
	int		rc;
	int		prev_fd;
}	t_buf;

static void	t_buf_init(t_buf *b, int fd)
{
	b->prev_fd = fd;
	b->cursor = NULL;
	b->rc = BUFFER_SIZE;
}

char	*get_next_line(int fd)
{
	static t_buf	b = {{0}, NULL, 0, -1};
	char			*next_line;

	next_line = NULL;
	if (b.prev_fd != fd)
		t_buf_init(&b, fd);
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
