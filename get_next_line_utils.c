/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:31 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/12 18:22:24 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = 0;
	printf("\ns1 : %s\n", s1);
	printf("\ns2 : %s\n", s2);
	if (s2 == 0)
		return (NULL);
	if (s1 != 0)
		while (s1[i])
			i++;
	while (s2[j])
		j++;
	if (!(s = malloc(1 + i + j)))
		return (0);
	i = -1;
	if (s1 != 0)
		while (s1[++i])
			s[i] = s1[i];
	j = -1;
	while (s2[++j])
		s[i + j] = s2[j];
	s[i + j] = '\0';
	printf("\ns : %s\n", s);
	return (s);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strcpyto(char *str, int i)
{
	char	*new;
	int		j;

	j = 0;
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j <= i)
	{
		new[j] = str[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strtocpy(char *str, int i, int size)
{
	char	*new;

	if (!(new = malloc(sizeof(char) * (size - i + 1))))
		return (NULL);
	while (i <= size)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
