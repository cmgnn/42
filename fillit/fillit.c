/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_octet			*get_matrix(t_octet *mat, int fd, int c)
{
	unsigned int	i;

	i = 0;
	while (i < 26)
		mat[i++] = 0;
	i = 1;
	mat[0] = (c == '#') ? (1) : 0;
	while (i < 16 && read(fd, &c, 1))
	{
		if (c == '\n')
		{
			mat[i / 4] = (0);
		}
		else if (c == '#' || c == '.')
		{
			mat[i / 4] += (c == '#') ? 1 << (i % 4) : 0;
			i++;
		}
		else
		{
			printf("an error occured %c\n", c);
			free(mat);
			return (NULL);
		}
	}
	read(fd, &c, 1);
	return (mat);
}

t_tetrinoid	**init_fillit(char **argv)
{
	int				fd;
	char			c;
	unsigned int	n;
	t_tetrinoid		**tab;

	n = 0;
	c = 1;
	tab = (t_tetrinoid **)malloc(sizeof(t_tetrinoid*) * 26);
	while (*argv)
	{
		fd = open(*argv, O_RDONLY);
		if (fd >= 0)
		{
			while (read(fd, &c, 1) && c)
			{
				if (c == '\n')
					read(fd, &c, 1);
				tab[n] = init_tetrinoid(NULL, n + 'A');
				get_matrix(tab[n]->mat, fd, c);
				if (c == '\n' || (n > 0 && !tab[n - 1]))
				{
					free_matrix(tab);
					free(tab);
					printf("map error\n");
					return (NULL);
				}
				reset_item(4, tab[n]->mat, 1);
				n++;
			}
		}
		else
			printf("file error\n");
		close(fd);
		argv++;
	}
	tab[n] = NULL;
	return (tab);
}

void		free_matrix(t_tetrinoid **tab)
{
	unsigned int	n;

	n = 0;
	while (tab[n])
	{
		free(tab[n]);
		n++;
	}
}
