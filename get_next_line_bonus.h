/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:37:47 by susami            #+#    #+#             */
/*   Updated: 2022/05/04 22:21:31 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
// FOPEN_MAX is declared in <stdio.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buf
{
	int		fd_len;
	int		fd[FOPEN_MAX];
	char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char	*cursor[FOPEN_MAX];
	ssize_t	rc[FOPEN_MAX];
}	t_buf;

// get_next_line_bonus.c
// static void	buf_init(t_buf *b, int fd)
// static char	*append_realloc(char *str, char c);
char			*get_next_line(int fd);

// get_next_line_utils_bonus.c
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
