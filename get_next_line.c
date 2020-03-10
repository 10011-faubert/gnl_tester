/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:08:13 by faubert           #+#    #+#             */
/*   Updated: 2020/03/07 15:49:52 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// modifier INT_MAX par la valeur max en fonction de sizeof(ssize)

char		*ft_read(char *str, int fd)
{
	char		*buf;
	long int	ret;
	int			i;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (NULL);
		if (ft_has_nl(str))
			break;
	}
	free(buf);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char		*str[FOPEN_MAX];
	char			*to_free;
	int				i;
	
	if (BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX || fd < 0 || fd >= FOPEN_MAX
			|| read(fd, str[fd], 0) < 0 || !line)
		return (-1);
	if (str[fd] == NULL || ft_has_nl(str[fd]) == 0)
	 	if ((str[fd] = ft_read(str[fd], fd)) == NULL)
			return (-1);
	i = ft_n_pos(str[fd]);
	*line = ft_substr(str[fd], 0, i);
	if (str[fd] != NULL && str[fd][i] == '\n')
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
