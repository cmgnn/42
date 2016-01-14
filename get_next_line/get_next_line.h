#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_fd
{
	int	fd;
	char	**buffer;
}		t_fd;

typedef struct t_list	t_fdlist;
int	get_next_line(const int fd, char **line);

# define BUFF_SIZE 10

#endif
