/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:27 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 06:42:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static int	prev_fd = -1;
	static char	buf[BUFFER_SIZE + 1] = {0};
	static int	rc = 0;
	static char	*cursor = NULL;
	static int	read_next = 1;
	char		*next_line;

	if (prev_fd != fd)
	{
		prev_fd = fd;
		rc = 0;
		cursor = NULL;
		read_next = 1;
	}
	next_line = NULL;
	if (cursor != NULL)
		next_line = strcat_realloc(NULL, cursor);
	while (1)
	{
		if (read_next && cursor == NULL)
		{
			rc = read(fd, buf, BUFFER_SIZE);
			if (rc < 0)
			{
				//printf("rc is negative.\n");
				return (NULL);
			}
			else if (rc < BUFFER_SIZE)
				read_next = 0;
			buf[rc] = '\0';
			cursor = buf;
			next_line = strcat_realloc(next_line, buf);
		}

		if (cursor == NULL)
			return (NULL);
		cursor = strchr(cursor, '\n');
		if (cursor == NULL)
		{
			if (next_line == NULL)
				return (NULL);
			else if (ft_strlen(next_line) == 0)
			{
				free(next_line);
				return (NULL);
			}
			else if (rc == BUFFER_SIZE)
				continue ;
			return (next_line);
		}
		if (cursor != NULL)
		{
			bzero(strchr(next_line, '\n') + 1, ft_strlen(cursor));
			cursor++;
			if (cursor == &buf[rc])
				cursor = NULL;
			return (next_line);
		}
	}
}
