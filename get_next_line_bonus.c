/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:37:14 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 23:06:56 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_fd_index(t_buf *b, int fd)
{
	int	i;

	i = 0;
	while (i < b->fd_len)
	{
		if (b->fd[i] == fd)
			return (i);
		i++;
	}
	if (i < FOPEN_MAX)
	{
		b->fd[i] = fd;
		b->rc[i] = BUFFER_SIZE;
		b->fd_len++;
		return (i);
	}
	return (-1);
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

// returns negative on error
static int	read_to_buf(t_buf *b, int fd, int i)
{
	b->rc[i] = read(fd, b->buf[i], BUFFER_SIZE);
	if (b->rc[i] < 0)
		return (-1);
	b->buf[i][b->rc[i]] = '\0';
	b->cursor[i] = b->buf[i];
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buf	b;
	char			*next_line;
	int				i;

	next_line = NULL;
	i = get_fd_index(&b, fd);
	while (b.cursor[i] || b.rc[i] == BUFFER_SIZE)
	{
		if (b.cursor[i] == NULL)
			if (read_to_buf(&b, fd, i) < 0)
				return (NULL);
		while (*b.cursor[i])
		{
			next_line = append_realloc(next_line, *b.cursor[i]);
			if (*b.cursor[i]++ == '\n')
				return (next_line);
		}
		b.cursor[i] = NULL;
	}
	b.rc[i] = BUFFER_SIZE;
	return (next_line);
}
