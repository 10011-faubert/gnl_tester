/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:09:19 by faubert           #+#    #+#             */
/*   Updated: 2020/10/30 18:19:52 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define OPEN_MAX 42
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"

int				main(void)
{
	int				fd1, fd2, fd3, fd4, fd5, fd6;
	char			*line1, *line2, *line3, *line4, *line5, *line6;
	short int		ret1 = 1, ret2 = 1, ret3 = 1, ret4 = 1, ret5 = 1, ret6 = 1;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	fd5 = open("test5.txt", O_RDONLY);

	printf("\n%lu", SSIZE_MAX);

	printf("\n//\n// \tReading test1.txt & test2.txt\n//\n");
	//while (ret1 > 0)
	//{
		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != -1)
		{
			printf("\n%d |%s", ret2, line2);
			free(line2);
		}
		else
			printf("\n%d", ret2);
		
		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != -1)
		{
			printf("\n%d |%s", ret2, line2);
			free(line2);
		}
		else
			printf("\n%d", ret2);
		
		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);

	//}

	return (0);
}
