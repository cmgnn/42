#include "get_next_line.h"
#include <stdio.h>

t_fd	*newfd(int fd, char *buffer)
{
	t_fd	*ptr;
	
	if ((ptr = (t_fd*)malloc(sizeof(t_fd))) != NULL)
	{
		ptr->fd = fd;
		ptr->buffer = ft_strsplit(buffer, '\n');
	}
	return (ptr);
}

char	*ft_realloc(char *addr, size_t len)
{
	char	*ptr = ft_strnew(len);

	ptr = ft_strcpy(ptr, addr);
	free(addr);
	return (ptr);
}

void	puttab(char **t)
{
	while (*t)
	{
		//printf("%s\n", *t);
		free(*t);
		t++;
	}
}

static	int	parse_list(const int fd, char *line, t_list *tmp)
{
	t_list *cur = NULL;
	t_fd	*ptr = NULL;

	while (tmp)
	{
		ptr = tmp->content;
		//printf("looking at : %d\n", ptr->fd);
		if (ptr && ptr->fd == fd && ptr->buffer)
		{
			if (*ptr->buffer)
			{
				//printf("found\n");
				ft_bzero(line, ft_strlen(line) + 1);
				line = ft_strncpy(line, *ptr->buffer, ft_strlen(*ptr->buffer));
				//printf("%s\n", *ptr->buffer);
				free(*ptr->buffer);
				*ptr->buffer = NULL;
				ptr->buffer++;
				return (1);
			}
			if (!*ptr->buffer)
			{
				//printf("end\n");
				free(ptr->buffer);
				ptr->buffer = NULL;
				free(ptr);
				ptr = NULL;
				if (cur)
					cur->next = tmp->next;
				free(tmp);
				tmp = NULL;
				return (0);
			}
		}
		cur = tmp;
		tmp = tmp->next;
	}
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*keep = NULL;
	t_list		*ptr = NULL;
	t_fd		*tmp = NULL;
	int		len = 1;
	char		*buffer = ft_strnew(BUFF_SIZE);

	if (fd < 0 || !line)
		return (-1);
	len = parse_list(fd, *line, keep);
	if (len != -1)
	{
		free(buffer);
		return (len);
	}
	while ((len = read(fd, buffer + ft_strlen(buffer), BUFF_SIZE)),
		len > 0)
	{
		buffer = ft_realloc(buffer, ft_strlen(buffer) + BUFF_SIZE);
	}
	tmp = newfd(fd, buffer);
	ptr = ft_lstnew(tmp, sizeof(t_fd));
	ft_lstadd(&keep, ptr);
	free(buffer);
	len = parse_list(fd, *line, keep);
	puttab(tmp->buffer);
	return (len);
}

int	main(int argc, char **argv)
{
	int	fd = 0;
	char	*buffer = ft_strnew(BUFF_SIZE);

	if (argc > 1)
	{
		argv++;
		fd = open(*argv, O_RDONLY);
		while (*argv)
		{
			printf("<%s>\n", *argv);
			while (get_next_line(fd, (char**)&buffer) > 0)
			{
				printf("line = <%s>\n", buffer);	
			}
			//printf("out = \n");
			//printf("<%s>\n", buffer);
			argv++;
		}
		close(fd);
	}
	free(buffer);
	return (0);
}
