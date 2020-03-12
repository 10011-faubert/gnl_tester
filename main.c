/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:09:19 by faubert           #+#    #+#             */
/*   Updated: 2020/03/07 11:19:41 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define OPEN_MAX 42
#define	CHECK_LEAKS
#include "leak_detector.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"

int				main(void)
{
	int				fd1, fd2, fd3, fd4, fd5, fd6;
	char			*line1, *line2, *line3, *line4, *line5, *line6;
	short int		ret1 = 1, ret2 = 1, ret3 = 1, ret4 = 1, ret5 = 1;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	fd5 = open("test5.txt", O_RDONLY);

	printf("\n%lu", SSIZE_MAX);

	printf("\n//\n// \tReading test1.txt & test2.txt\n//\n");
	while (ret1 > 0)
	{
		ret1 = get_next_line(fd1, &line1);
		if (ret1 != -1)
		{
			printf("\n%d |%s", ret1, line1);
			free(line1);
		}
		else
			printf("\n%d", ret1);
	}

	while (ret2 > 0)
	{
		ret2 = get_next_line(fd2, &line2);
		if (ret2 != -1)
		{
			printf("\n%d |%s", ret2, line2);
			free(line2);
		}
		else
			printf("\n%d", ret2);
	}


	printf("\n\n//\n// \tReading test3.txt (nl)\n//\n");
	while (ret3 > 0)
	{
		ret3 = get_next_line(fd3, &line3);
		if (ret3 != -1)
		{
			printf("\n%d |%s", ret3, line3);
			free(line3);
		}
		else
			printf("\n%d", ret3);
	}


	printf("\n\n//\n// \tReading test4.txt (empty)\n//\n");
	while (ret4 > 0)
	{
		ret4 = get_next_line(fd4, &line4);
		if (ret4 != -1)
		{
			printf("\n%d |%s", ret4, line4);
			free(line4);
		}
		else
			printf("\n%d", ret4);
	}


	printf("\n\n//\n// \tReading bitconnect (missing file)\n//\n");
	while (ret5 > 0)
	{
		ret5 = get_next_line(fd5, &line5);
		if (ret5 != -1)
		{
			printf("\n%d |%s", ret5, line5);
			free(line5);
		}
		else
			printf("\n%d", ret5);
	}


	printf("\n\n//\n// \tReading fd 0 standard input 'q' to quit\n//\n");
	while (line6)
	{
		get_next_line(0, &line6);
		if (*line6 == 'q')
		{
			break;
		}
		free(line6);
	}
	free(line6);

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	printf("\n");
	__print_leaks();
	return (0);
}
