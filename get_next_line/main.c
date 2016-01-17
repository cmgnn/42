#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char *line = ft_strnew(1024);
	int		fd = 0;

	if (argc)
	{
		argv++;
		while (*argv)
		{
			fd = open(*argv, O_RDONLY);
			ft_putendl(*argv);
			while (get_next_line(fd, &line) > 0)
			{
				ft_putstr("(out)");
				ft_putendl(line);
			}
			close(fd);
			argv++;
		}
	}
	free(line);
	return (0);
}