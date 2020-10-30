/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:08:13 by faubert           #+#    #+#             */
/*   Updated: 2020/10/30 15:20:09 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_read(char *str, int fd)
{
	char		*buf;
	size_t		ret;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (NULL);
		if (ft_has_nl(str))
			break ;
	}
	free(buf);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char		*str[FOPEN_MAX];
	char			*to_free;
	size_t			i;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX - 1 || fd < 0
	|| fd >= FOPEN_MAX || read(fd, str[fd], 0) < 0 || !line
	|| ((str[fd] == NULL || ft_has_nl(str[fd]) == 0)
	&& ((str[fd] = ft_read(str[fd], fd)) == NULL)))
		return (-1);
	i = ft_nl_pos(str[fd]);
	*line = ft_substr(str[fd], 0, i);
	if (str[fd] != NULL && ft_has_nl(&str[fd][i]))
	{
		to_free = str[fd];
		str[fd] = ft_substr(to_free, i + 1, ft_strlen(to_free));
		free(to_free);
		return (str[fd] ? 1 : -1);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}
