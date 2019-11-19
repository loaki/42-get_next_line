/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:51 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/19 19:20:11 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char			*ft_strdup(char *src);
int				ft_substr(char *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
int				ft_strjoin(char **s1, char *s2);
int				ft_find_nl(char *buffer);
int				get_next_line(int fd, char **line);

#endif
