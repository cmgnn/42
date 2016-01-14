#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
static int	split(char *buf, char *dst, char *s);

static int	split(char *buf, char *dst, char *s)
{
	int i = 0, j = 0;
	if (buf && dst && s)
	{
		while (s[i] && s[i] != '\n')
		{
			dst[i] = s[i];
			//s[i] = s[i + 1];
			i++;
		}
//	dst[i] = '\0';
//	printf("<%s>", dst);
//	printf("1\n");
		j = i;
		if (s[i])
			i++;
		else
			return (i);
		i = 0;
//	printf("2\n");
//	printf("wtf\n");
//		*buf = 0;
		while (s[j])
		{
			buf[i] = s[j];
			s[i] = s[j + 1];
			i++;
			j++;
		}
//	printf("3\n");
		return (i - j);
	}
	return (-1);
}

char	*ft_realloc(char *addr, size_t len)
{
	char	*ptr;

	ptr = ft_strnew(len);
	ft_strcpy(ptr, addr);
	free(addr);
	return(ptr);
	addr = ft_strnew(len);
	ft_strcpy(addr, ptr);
	free(ptr);
	return (addr);
}

int		get_next_line(const int fd, char **line)
{
	static char		*(keep[99]);
	int		len = -1;
	char		*buffer = NULL;
	//int			ret = 1;

	if (fd < 0 || !line)
		return (-1);
	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE);
	ft_bzero(buffer, BUFF_SIZE);
	len = split(keep[fd], buffer, keep[fd]);
	if (len > 0)
	{
		len += BUFF_SIZE;
		buffer = ft_realloc(buffer, len + 1);
	}else{
		free(keep[fd]);
		keep[fd] = NULL;
		len = 0;
	}buffer[len + 1] = 0;
	//printf("keep :%s\n", keep[fd]);
	while (ft_strchr(buffer, '\n') == NULL && read(fd, buffer + len, BUFF_SIZE) > 0)
	{
		len += BUFF_SIZE;
		printf("<%d<%s>\n", len, buffer);
		buffer = (char*)ft_realloc(buffer, (len + 1));
		buffer[len + 1] = 0;
	}
	if (!keep[fd])
		keep[fd] = (char*)malloc(sizeof(char) * (len + 1));
	if (!*line)
	{
		*line = ft_strnew(len);
	}
	len = split((char*)keep[fd], *line, buffer);
	if (keep[fd] && len == 0)
	{
		free(keep[fd]);
		keep[fd] = NULL;
	}
	free(buffer);
	return (!!len);
}

