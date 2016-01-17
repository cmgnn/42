#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>
# include "libft/includes/libft.h"

int			get_next_line(const int fd, char **line);

# define BUFF_SIZE 100

#endif
