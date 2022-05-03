/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:43 by susami            #+#    #+#             */
/*   Updated: 2022/05/03 21:34:00 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buf
{
	char	buf[BUFFER_SIZE + 1];
	char	*cursor;
	int		rc;
	int		prev_fd;
}	t_buf;

// get_next_line.c
// static void	buf_init(t_buf *b, int fd)
// static char	*append_realloc(char *str, char c);
char			*get_next_line(int fd);

// get_next_line_utils.c
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
