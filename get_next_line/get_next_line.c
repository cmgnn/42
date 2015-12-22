#include "get_next_line.h"
void	print(const char *str, ...);
/*static	char	*cpy(char *line, char *src)
{
	if(*src)
	{
		*line = *src;
		cpy(line + 1, src + 1);
	}
	return (line);
}
*/

static	void	*ft_realloc(void *addr, size_t last_size, size_t new_size)
{
	void *tmp = malloc(last_size);
	if (addr)
	{
		bzero(tmp, new_size);
		tmp = memcpy(tmp, addr, last_size);
		//free(addr);
	}
	return (tmp);
}

int get_next_line(int const fd, char **line)
{
	unsigned int i = 0, n = 1;
	char *tmp;

	if (line && fd >= 0)
	{
		tmp = *line;
		if (*line)
		{
			while (read(fd, &tmp[i], 1) && tmp[i] != '\n')
			{
				if (i == BUFF_SIZE * n)
				{
					tmp = ft_realloc(tmp, sizeof(char) * BUFF_SIZE * n, sizeof(char) * BUFF_SIZE * (n + 1));
					n++;
				}
				i++;
			}
			if (tmp[i] == '\n' && i < BUFF_SIZE)
			{
				tmp[i] = 0;
				return (1);
			}
			else if (i < BUFF_SIZE)
			{
				tmp[i] = 0;
				return (0);
			}
		}
	}
	return (-1);
}

