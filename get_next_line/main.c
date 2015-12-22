#include "get_next_line.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	char	*buffer = (char*)malloc(sizeof(char) * BUFF_SIZE);

	int	ret = 1;
	argv++;
	while (argv && *(argv) && argc)
	{
		int fd = open(*argv, O_RDONLY);
		while ((ret = get_next_line(fd, (char**)&buffer)) > 0)
			printf("%s\n", buffer);
		close(fd);
		argv++;
	}
	//free(buffer);
	return (1);
}
