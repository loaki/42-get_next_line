/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:12:29 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/17 16:46:23 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	size_t			j;

	j = 0;
	s2 = 0;
	while (s[j] && j < start)
		j++;
	if (j != start)
		return (NULL);
	j = 0;
	while (s[start + j] && j < len)
		j++;
	if (!(s2 = malloc(j + 1)))
		return (0);
	j = 0;
	while (s[start + j] && j < len)
	{
		s2[j] = s[j + start];
		j++;
	}
	s2[j] = 0;
	return (s2);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(s = malloc(sizeof(char *) * (1 + i + j))))
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	while (s2[++j])
		s[i + j] = s2[j];
	s[i + j] = '\0';
	return (s);
}
