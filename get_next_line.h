/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:43 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 21:38:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

char	*get_next_line(int fd);

// utils.c
size_t	ft_strlen(const char *s);
// static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*strcat_realloc(char *dst, char *src);
#endif
