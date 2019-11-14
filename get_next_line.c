/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:25:36 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/14 18:57:12 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_eof(char **line, char *str, char *buffer, int eof)
{
	if (eof != 0 && eof != BUFFER_SIZE)
	{
		if (ft_find_nl(buffer) != -1)
		{
			if (!(str = ft_strjoin(str, ft_substr(buffer, 0, eof - 1))))
				return (-1);
			*line = str;
			return (1);
		}
		else
		{
			if (!(str = ft_strjoin(str, ft_substr(buffer, 0, eof))))
				return (-1);
			*line = str;
			return (0);
		}
	}
	*line[0] = '\0';
	free(str);
	return (0);
}

int		ft_find_nl(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int				nl;
	int				eof;
	char			buffer[BUFFER_SIZE + 1];
	static char		*str[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line || (read(fd, 0, 0) == -1))
		return (-1);
	buffer[BUFFER_SIZE] = '\0';
	if (str[fd] == NULL)
		if (!(str[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	str[fd][BUFFER_SIZE] = '\0';
	while (((nl = ft_find_nl(str[fd])) == -1) &&
		((eof = read(fd, buffer, BUFFER_SIZE)) == BUFFER_SIZE))
		if (!(str[fd] = ft_strjoin(str[fd], buffer)))
			return (-1);
	if (nl >= 0)
	{
		*line = ft_substr(str[fd], 0, nl);
		str[fd] = ft_substr(str[fd], nl + 1, ft_strlen(str[fd]));
		return (1);
	}
	return (ft_eof(line, str[fd], buffer, eof));
}
