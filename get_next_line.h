/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:51 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/12 18:22:26 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_struct
{
	char	*buff;
	int		nl;
}				t_struct;

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
char			*ft_strcpyto(char *str, int i);
char			*ft_strtocpy(char *str, int i, int size);

int				read_file(int fd, t_struct *buffer);
int				malloc_line(char **line, char *buff);
int				find_nl(t_struct *buffer);
int				next_buffer(char **line, t_struct *buffer);
int				get_next_line(int fd, char **line);
#endif
