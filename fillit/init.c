/* ******************************************************************************************************* */
/*            I N I T I A L I Z E R                                                                    	*/
/* ******************************************************************************************************* */
#include "head.h"

t_solution	*init_solution(char *buffer, unsigned int size)
{
	t_solution	*s;

	if((s = (t_solution*)malloc(sizeof(t_solution))) != NULL)
	{
		s->size = size;
		s->buffer = buffer;
	}
	return (s);
}

t_tetrinoid	*init_tetrinoid(unsigned int *mat, char c)
{
	t_tetrinoid	*t;

	if ((t = malloc(sizeof(t_tetrinoid))) != NULL)
	{
		t->c = c;
		t->mat = mat;
	}
	return (t);
}

void		free_tetrinoid(t_tetrinoid *t)
{
	free(t->mat);
	free(t);
}

void		build_solution(unsigned int size, t_solution *s, t_tetrinoid *item)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			s->buffer[i + j * size] = (((1 << j) & item->mat[i]) >> j) ? (item->c) : (s->buffer[i + j * size]);
			j++;
		}
		i++;
	}
}

void		leave_solution(unsigned int size, t_solution *s, t_tetrinoid *item)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (s->buffer[i + j * size] == item->c)
				s->buffer[i + j * size] = '.';
			j++;
		}
		i++;
	}
}

unsigned int	*reset_item(unsigned int size, unsigned int *item, int flag)
{
	unsigned int n;
	int bool;

	n = 0;
	bool = 0;
	while (!bool)
	{
		n = 0;
		while (n < size && !(item[n] != 0 && item[n] % 2 == 1))
		{
			n++;
		}
		if (item[n] % 2 == 1)
		{
			//print("merde ");
			bool = 1;
		}
		n = 0;
		while (!bool && n < size)
		{
			//print("divide");
			item[n] = item[n] >> 1;
			n++;
		}
	}
	if (flag && !item[0])
	{
		n = 0;
		while (n < size && !item[n])
		{
            		n++;
		}
		bool = 0;
		while (n < size && item[n])
		{
			item[bool] = item[n];
			item[n] = 0;
			n++;
			bool++;
		}
	}
	return (item);
}
