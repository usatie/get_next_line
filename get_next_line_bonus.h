/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:37:47 by susami            #+#    #+#             */
/*   Updated: 2022/05/11 07:27:45 by susami           ###   ########.fr       */
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
	int		fds[FOPEN_MAX];
	char	bufs[FOPEN_MAX][BUFFER_SIZE + 1];
	char	*cursors[FOPEN_MAX];
	ssize_t	rcs[FOPEN_MAX];
}	t_buf;

// get_next_line_bonus.c
char			*get_next_line(int fd);

// get_next_line_utils_bonus.c
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
