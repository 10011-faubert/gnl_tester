/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:08:24 by faubert           #+#    #+#             */
/*   Updated: 2020/03/12 10:18:00 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include <limits.h> // check if needed
# include <stdint.h> // check if needed

short int	ft_has_nl(const char *str);
size_t		ft_nl_pos(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_substr(const char *s, size_t start, size_t len);
char		*ft_read(char *str, int fd);
int			get_next_line(int fd, char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255 
# endif

#endif
