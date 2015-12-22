#include "head.h"

/* ********************************************************************************************************/
/* *             A F F I C H A G E                                                                        */
/* ********************************************************************************************************/
void    print_base(unsigned int value, char c, unsigned int bits)
{
    unsigned int i = 0;
    while (i < bits)
    {
        print("%c", !((1 << i) & value) >> i ?('.'):(c));
        value = value >> 1;
        bits--;
    }
}

void    print_solution(t_solution *s)
{
    unsigned int i = 0, j = 0;
    while (i < s->size)
    {
        j = 0;
        while (j < s->size)
        {
            print("%c", s->buffer[i + s->size * j]);
            j++;
        }
        print("\n");
        i++;
    }
}
void    print_tab(unsigned int *tab, unsigned int size, char c)
{
    unsigned int i = 0;
    if (tab)
    while (i < size)
    {
        print_base(tab[i], (c)?c :'#', size);
        print(" | %d\n", tab[i]);
        i++;
    }
    else
        print("(null)");
    print("\n");
}





/* ***************************************************************************************************/
/* *                 A D D I T I O N A L S _ F O N C T I O N S					     */
/* ***************************************************************************************************/

unsigned int	*get_matrix(int fd, int c)
{
	unsigned int	*mat;
	unsigned int	i;

	mat = (unsigned int*)malloc(sizeof(unsigned int) * 26);
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
			print("an error occured %c\n", c);
			free(mat);
			return (NULL);
		}
	}
	read(fd, &c, 1);
	return (mat);
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

t_tetrinoid	**init_fillit(char **argv)
{
	int		fd;
	char		c;
	unsigned int	n;
	t_tetrinoid	**tab;

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
				tab[n] = init_tetrinoid(get_matrix(fd, c), n + 'A');
				if (c == '\n' || (n > 0 && !tab[n - 1]))
				{
					free_matrix(tab);
					free(tab);
					print("map error\n");
					return (NULL);
				}
				tab[n]->mat = reset_item(4, tab[n]->mat, 1);
				n++;
			}
		}
		else
		    print("file error\n");
		close(fd);
		argv++;
	}
	tab[n] = NULL;
	return (tab);
}

int		main(int argc, char **argv)
{
	char    buffer[1000000];
	unsigned int ref[26];
	t_solution *s;
	t_tetrinoid **TAB;
	unsigned int i;
	TAB = NULL;
	s = NULL;
	i = 0;
	if (argc && argv)
	{
		while (i < 10000)
		{
			buffer[i++] = '.';
		}
		i = 0;
		while (i < 26)
		{
			ref[i++] = 0;
		}
		s = init_solution(buffer, 10);
		TAB = init_fillit(argv + 1);
		if (TAB)
		{
			v3(TAB, 0, ref, s);
			print_solution(s);
			i = 0;
			while (TAB[i])
			{
				free_tetrinoid(TAB[i]);
				i++;
			}
			free(TAB);
			free(s);
		}
	}
	else
		print("OOOOH my god !\n");
	return (0);
}
	
