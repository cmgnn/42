#ifndef GNL_H
# define GNL_H
# ifndef BUFF_SIZE
# define BUFF_SIZE 3
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
int	get_next_line(int const fd, char **line);
#define gnl(x,l)	get_next_line(x,l)
#endif

