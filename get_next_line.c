/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:08:13 by faubert           #+#    #+#             */
/*   Updated: 2020/02/27 17:39:53 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_read(char *str, int fd)
{
	char	*buf;
	int		ret;
	int		i;
	char	*tmp;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	i = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buf);
		free(tmp);
		while (str[i])
		{
			if (str[i] == '\n')
				return (str);
			i++;
		}
	}
	free(buf);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	int				i;
	char			*tmp;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= OPEN_MAX || read(fd, str[fd], 0) < 0
			|| !line)
		return (-1);
	if (str[fd] == NULL || ft_has_n(str[fd]) == 0)
		str[fd] = ft_read(str[fd], fd);
	if (str[fd] == NULL)
		return (*line = ft_strdup("")) != NULL ? 0 : -1;
	i = ft_n_pos(str[fd]);
	*line = ft_substr(str[fd], 0, i);
	if (str[fd] != NULL && str[fd][i] == '\n')
	{
		tmp = str[fd];
		str[fd] = ft_substr(tmp, i + 1, ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}
