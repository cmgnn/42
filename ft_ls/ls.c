#include "ls.h"

t_file	*init_file(char *name)
{
	t_file *file;
	
	if ((file = (t_file*)malloc(sizeof(t_file))))
	{
		file->name = name;
		file->dir = NULL;
		file->next = NULL;
		stat(name, &file->dat);
	}
	return (file);
}

int		parcours(t_file *f)
{
	int i = 0;
	while (f)
	{
		i++;
		printf("%s\n", f->name);
		if (f->dir)
			printf("\t");
		parcours(f->dir);
		f = f->next;
	};
	return (i);
}

void	del(t_file *f)
{
	while (f)
	{
		del(f->dir);
		free(f);
		f = f->next;
	}
}

void	addfile(t_file **f, t_file *add)
{
	t_file *tmp;

	tmp = *f;
	if (*f)
	{
		while (tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
	}
	else
		*f = add;
}

char	*set_name_path(char *path, char *dirname)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(path) +
					ft_strlen(dirname) +
					ft_strlen(PATH_SEPARATOR));
	ft_strcpy(tmp, path);
	ft_strcat(tmp, dirname);
	ft_strcat(tmp, PATH_SEPARATOR);
	return (tmp);
}

t_file	*ft_open(char *name, int deep)
{
	t_dir	*entry;
	t_file	*file;
	t_file	*ret;
	DIR		*d;
	char	*tmp = NULL;

	d = opendir(name);
	ret = NULL;
	if (d)
	{
		while ((entry = readdir(d)))
		{
			if (ft_strcmp(entry->d_name, "..") && ft_strcmp(entry->d_name, "."))
			{
				file = init_file(entry->d_name);
				printf("%s\n", entry->d_name);
				if (entry->d_type & DT_DIR && deep != 0)
				{
					tmp = set_name_path(name, entry->d_name);
					file->dir = ft_open(tmp, deep - 1);
					ft_memdel((void**)&tmp);
				}
				addfile(&ret, file);
			}
		}
		closedir(d);
	}
	else
		printf("cannot acces to %s\n", name);
	return (ret);
}

void	set_options(t_args *tmp, char *argv)
{
	while (*argv)
	{
		if (*argv == 'l')
			tmp->mask |= LIST;
		else if (*argv == 'R')
			tmp->deep = ft_isdigit(argv + 1) ? ft_atoi(*argv) : -1;
		else if (*argv == 'r')
			tmp->mask |= REVERSE;
		else if (*argv == 'a')
			tmp->mask |= ALL;
		else if (*argv == 'S')
			tmp->mask |= SORT;
		(*argv)++;
	}	
}



int		main(int argc, char **argv)
{
	t_args	tmp;
	t_file	*root;

	argv++;
	if (!argc)
		ft_putstr_fd("OHHHHH my god!!!\n", 2);
	while (*argv)
	{
		if (**argv == '-')
		{
			set_options(&tmp);
		}
		else
			tmp.path = *argv;
		argv++;
	}
	root = ft_open(tmp.path, tmp.deep);
	return (ls(&tmp, root));
}
