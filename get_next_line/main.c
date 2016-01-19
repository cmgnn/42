#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char 	line[1024] = {0};
	int		fd = 0;
	char *ptr = line;
	if (argc)
	{
		argv++;
		while (*argv)
		{
			fd = open(*argv, O_RDONLY);
			ft_putendl(*argv);

			while (get_next_line(fd, &ptr) > 0)
			{
				ft_putstr("(out)");
				ft_putendl(line);
			}
			close(fd);
			argv++;
		}
	}
	//free(line);
	return (0);
}