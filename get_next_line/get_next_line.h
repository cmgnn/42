#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdlib.h>
#include "../../Documents/42/libft/libft.h"

typedef struct	s_fd
{
	int	fd;
	char	**buffer;
}		t_fd;

typedef struct t_list	t_fdlist;

#define BUFF_SIZE 200

#endif
