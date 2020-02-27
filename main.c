/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:09:19 by faubert           #+#    #+#             */
/*   Updated: 2020/02/27 22:13:28 by faubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int				main(void)
{
	int             fd1;
	int             fd2;
	int             fd3;
	int             fd4;
	char            *line1;
	char            *line2;
	char			*line3;
	char			*line4;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	int             ret1 = 1;
	int             ret2 = 1;
	int             ret3 = 1;
	int             ret4 = 1;

	printf("\n//\n// \tReading files test1.txt & test2.txt\n//\n");
	/*
	for (int i = 0; i < 3; i++)
	{
		ret1 = get_next_line(fd1, &line1);
		printf("\n%d |%s", ret1, line1);
	}
	for (int i = 0; i < 7; i++)
	{
		ret2 = get_next_line(fd2, &line2);
		printf("\n%d |%s", ret2, line2);
	}
	*/

	while ((ret1 = get_next_line(fd1, &line1)) > 0)
		printf("\n%d |%s", ret1, line1);

	/*
	while ((ret2 = get_next_line(fd2, &line2)) > 0)
		printf("\n%d |%s", ret2, line2);
	
	printf("\n\n//\n// \tReading file test3.txt\n//\n");
	ret3 = get_next_line(fd3, &line3);
	printf("\n%d |%s", ret3, line3);
	ret3 = get_next_line(fd3, &line3);
	printf("\n%d |%s", ret3, line3);
	
	printf("\n\n//\n// \tReading file test4.txt\n//\n");
	ret4 = get_next_line(fd4, &line4);
	printf("\n%d |%s", ret4, line4);

	*/
	close(fd1);
	free(line1);
	CHECK_LEAKS;
	return (0);
}
