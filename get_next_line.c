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
#include "stdio.h"

// modifier INT_MAX par la valeur max en fonction de sizeof(ssize)

char		*ft_read(char *str, int fd)
{
	char	*buf;
	long int		ret;
	int		i;
	//long int		j = BUFFER_SIZE;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	i = 0;
	//printf("\n===%ld===\n", j);
	//printf("\nsize_t : %lu\n", sizeof(size_t));
	//printf("\nssize_t : %lu\n", sizeof(ssize_t));
	//printf("\nint : %lu\n", sizeof(int));
	while ((ret = (long int)read(fd, buf, BUFFER_SIZE)) != 0)
	{
		//printf("\n===%lu===\n", ret);
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
			return (NULL);
		while (str[i])
			if (str[i++] == '\n')
			{
				free(buf);
				return (str);
			}
	}
	free(buf);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	int				i;
	char			*to_free;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX || fd < 0 || fd >= OPEN_MAX
			|| read(fd, str[fd], 0) < 0 || !line)
		return (-1);
	if (str[fd] == NULL || ft_has_n(str[fd]) == 0)
//		str[fd] = ft_read(str[fd], fd);
	 	if ((str[fd] = ft_read(str[fd], fd)) == NULL)
			return (-1);
//	rentre en conflit avec une file vide (touch)
	if (str[fd] == NULL)
		return (*line = ft_strdup("")) != NULL ? 0 : -1;
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
