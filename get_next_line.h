#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct	s_struct
{
	char				*buff;
	int					current;
	struct	s_struct	*next;
}				t_struct;

#endif
