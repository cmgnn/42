#include "get_next_line.h"

static	char	*realloc_buffer(char *addr, size_t len)
{
	char	*ptr;

	if (addr && (ptr = ft_strnew(len)))
	{
		ft_strcpy(ptr, addr);
		ptr[len] = 0;
		free(addr);
	}
	return(ptr);
}

static	char	*set_line(char *buf, char *line, size_t len)
{
	size_t index = 0;

	while (index < len && *buf != '\n' && *buf)
	{
		line[index] = *(buf++);
		index++;
	}
	if (*buf)
		buf++;
	line[index] = 0;
	return (buf);
}

static	int		read_buffer(const int fd, char **line)
{
	static char *(keep[255]) = {0};
	char		*buf;
	int	len;
	int	ret;

	ret = 1;
	buf = ft_strnew((keep[fd]) ? ft_strlen(keep[fd]) : BUFF_SIZE);
	buf[0] = 0;
	if (keep[fd])
	{
		ft_strcpy(buf, keep[fd]);
		free(keep[fd]);
		keep[fd] = NULL;
	}
	len = ft_strlen(buf);
	while (ret > 0) 
	{
		if (!ft_strchr(buf, '\n'))
		{
			len += BUFF_SIZE;
			buf = realloc_buffer(buf, len);
			ret = read(fd, &buf[len - BUFF_SIZE], (size_t)(BUFF_SIZE));
			if (ret < 0)
			{
				ft_memdel((void**)&keep[fd]);
				ft_memdel((void**)&buf);
				return (-1);
			}
		}
		else
			ret = -1;
	}
	if (!*line)
		*line = ft_strnew(len);
	//printf("line<%s>\n", buf);
	if (keep[fd])
		ft_memdel((void**)&keep[fd]);
	keep[fd] = ft_strnew(len);
	keep[fd] = ft_strcpy(keep[fd], set_line(buf, *line, len));	
	if (!*buf)
	{
		ft_memdel((void**)&keep[fd]);
		ft_memdel((void**)&buf);
		return -1;
	}
	ft_memdel((void**)&buf);
	return (!!len);
}

int	get_next_line(int const fd, char **line)
{
	int size = 0;

	if (fd < 0 || !line)
		return (-1);
	size = read_buffer(fd, line);
	if (size < 0)
		return (-1);
	return (size);
}