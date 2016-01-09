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
void	*ft_memcpy(void *dst, const void *src, size_t len);
char*	ft_strsub(char *dst, int c);


static	void	*ft_realloc(void *addr, size_t last_size, size_t new_size)
{
	ft_printf("re");
	void *tmp = malloc(last_size);
	if (addr && tmp)
	{
		ft_bzero(tmp, new_size);
		tmp = ft_memcpy(tmp, addr, last_size);
		free(addr);
	}
	ft_printf("\n");
	return (tmp);
}

int get_next_line(int const fd, char **line)
{
	unsigned int i = 0, n = 1;
	static char *tmp = NULL;

	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if (line && fd >= 0)
	{
		if (*line)
		{
			while ((i = read(fd, &tmp[BUFF_SIZE * n], BUFF_SIZE)))
			{
				ft_printf("<%s>", tmp);
				tmp = ft_realloc(tmp, sizeof(char) * BUFF_SIZE * n, sizeof(char) * BUFF_SIZE * (n + 1));
				n++;
			}
			*line = ft_strsub(tmp, '\n');
			return (!!i);
		}
		
	}
	return (-1);
}

