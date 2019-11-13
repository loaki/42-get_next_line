/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:25:36 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/13 16:28:55 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int				n;
	int				o;
	char			buffer[BUFFER_SIZE];
	static char		*str[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE == 0)
		return (-1);
	if (str[fd] == NULL)
		if (!(str[fd] = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
			return (-1);
	str[fd][BUFFER_SIZE + 1] = '\0';
	while (((o = read(fd, buffer, BUFFER_SIZE)) > 0) &&
		((n = ft_find_nl(buffer)) >= 0))
		if (!(str[fd] = ft_strjoin(str[fd], buffer)))
			return (-1);
	if (n >= 0)
	{
		*line = ft_substr(str[fd], 0, n);
		str[fd] = ft_substr(str[fd], n + 1, ft_strlen(str[fd]));
		return (1);
	}
	*line = ft_substr(str[fd], 0, ft_strlen(str[fd]));
	free(str);
	return (0);
}
