/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:19:17 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/20 16:45:46 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int r;

	line = NULL;
	fd = open("toto", O_RDONLY);
	r = 1;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		printf("(ret : %i) : %s\n",r, line);
		free(line);
	}
	printf("(ret : %i) : %s\n",r, line);
	free(line);

	int fd1;
	fd1 = open("bigtext", O_RDONLY);
	r = get_next_line(fd, &line);
	printf("(ret : %i) : %s\n",r, line);
	free(line);
	r = get_next_line(fd1, &line);
	printf("(ret : %i) : %s\n",r, line);
	free(line);
	r = get_next_line(fd, &line);
	printf("(ret : %i) : %s\n",r, line);
	free(line);
	r = get_next_line(fd1, &line);
	printf("(ret : %i) : %s\n",r, line);
	free(line);
	r = get_next_line(fd, &line);
	printf("(ret : %i) : %s\n",r, line);
	free(line);

}
