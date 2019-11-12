/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:56 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/12 18:22:20 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_file(int fd, t_struct *buffer)
{
	if (!(buffer->buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (read(fd, (buffer->buff), BUFFER_SIZE) == -1)
		return (-1);
	(buffer->buff)[BUFFER_SIZE + 1] = '\0';
	return (0);
}

int		malloc_line(char **line, char *buff)
{
	if (!(*line = ft_strjoin(*line, buff)))
		return (-1);
	return (0);
}

int		find_nl(t_struct *buffer)
{
	int i;

	i = 0;
	while ((buffer->buff)[i] && i <= BUFFER_SIZE)
	{
		if ((buffer->buff)[i] == '\n')
			return (1);
		//if ((buffer->buff)[i] == '\0')
		//	return (0);
		i++;
	}
	buffer->nl = i;
	return (2);
}

int		next_buffer(char **line, t_struct *buffer)
{
	int		ret;
	char	*str;

	ret = find_nl(buffer);
	if (!(str = ft_strdup(buffer->buff)))
		return (-1);
	if (!(str = ft_strcpyto(buffer->buff, buffer->nl)))
		return (-1);
	if (!(buffer->buff = ft_strtocpy(buffer->buff, buffer->nl, BUFFER_SIZE)))
		return (-1);
	if (!(malloc_line(line, str)))
		return (-1);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static t_struct		*buffer;

	if (fd == -1)
		return (-1);
	if (buffer == 0)
	{
		if (!(buffer = malloc(sizeof(t_struct))))
			return (-1);
		buffer->buff = 0;
	}
	if (buffer->buff == NULL)
		if (read_file(fd, buffer) == -1)
			return (-1);
	write (1, "1\n", 2);
	while (find_nl(buffer) == 2)
	{
		printf("buff ' %s", buffer->buff);
		if (malloc_line(line, buffer->buff) == -1)
			return (-1);
		write (1, "xx\n", 3);
		if (read_file(fd, buffer) == -1)
			return (-1);
		write (1, "gg\n", 3);
	}
	return (next_buffer(line, buffer));
}
