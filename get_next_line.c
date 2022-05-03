/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:27 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 19:22:22 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	static int	prev_fd = -1;
	static char	*cursor = NULL;
	static int	rc = -1;
	static int	read_next = 1;
	char		*next_line;

	next_line = NULL;
	if (prev_fd != fd)
	{
		prev_fd = fd;
		cursor = NULL;
		read_next = 1;
	}
	while (cursor || read_next)
	{
		if (cursor == NULL)
		{
			rc = read(fd, buf, BUFFER_SIZE);
			// 1. read fail
			if (rc < 0)
				return (NULL);
			buf[rc] = '\0';
			cursor = buf;
			if (rc < BUFFER_SIZE)
				read_next = 0;
		}
		while (*cursor)
		{
			// 1. append(next_line, *cursor)
			next_line = append_realloc(next_line, *cursor);
			// 2. if *cursor == '\n' return
			if (*cursor++ == '\n')
				return (next_line);
		}
		// 2. if cursor is '\0'
		cursor = NULL;
	}
	return (next_line);
}
