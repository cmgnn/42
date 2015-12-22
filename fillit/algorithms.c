/*********************************************************************************************************/
/**             M O V E _ T E T R I N O I D                                                              */
/*********************************************************************************************************/
#include "head.h"
unsigned int	*move_left(unsigned int *item, unsigned int size)
{
	unsigned int	n;

	n = 0;
	while (n < size)
	{
		item[n] = item[n] << 1;
		n++;
	}
	return (item);
}

unsigned int	*move_down(unsigned int *ref, unsigned int *item, unsigned int size)
{
	unsigned int	n;
	unsigned int	j;

	j = 0;
	while (ref[j] != 0)
	{
		j++;
	}
	item = reset_item(size, item, 0);
	n = size - 1;
	while (n > 0)
	{
		item[n] = item[n-1];
		n--;
	}
	item[0] = 0;
	return (item);
}

int		move_item(unsigned int *ref, unsigned int size, unsigned int *tmp, int bool)
{
	int	b;

	b = 0;
	if (bool)
		tmp = move_left(tmp, size);
	while (b < 1)
	{
		b = verification(ref, tmp, size);
		if (b == 0)
			tmp = move_down(ref, tmp, size);
		else if (b == -1)
			tmp = move_left(tmp, size);
		else if (b == -2)
		{
			tmp = reset_item(size, tmp, 1);
			return (0);
		}
	}
	return (1);
}

/*********************************************************************************************************/
/**             A L G O R I T H M S                                                                      */
/*********************************************************************************************************/
unsigned int	bits_fort(unsigned int value, unsigned int n)
{
	if (value && n)
		return ((1 << n) & value) ? (n) : bits_fort(value, n - 1);
	return (0);
}

unsigned int	bits_faible(unsigned int value, unsigned int n)
{
	return ((1 << n) & value) ? (n) : bits_faible(value, n + 1);
}

int             solution(unsigned int size, unsigned int *ref, t_solution **s)
{
	unsigned int	i;
	unsigned int	d_xm;
	unsigned int	d_ym;
	unsigned int	d_xM;
	unsigned int	d_yM;

	i = 0;
	d_xM = 0;
	if (ref[size])
		return 0;
	while (i < size && !(ref[i]))
		i++;
	d_ym = i;
	while (i < size)
	{
		d_xm = bits_fort(ref[i], size) + 1;
		if (d_xM < d_xm)
			d_xM = d_xm;
		/*if (ref[i])
			d_yM = bits_faible(ref[i], 0);print("b\n");
		if (d_yM < d_xm)
			d_yM = d_xm;*/
		i++;
	}
	while (i > 0 && !ref[i-1])
		i--;
	d_xm = 0;//d_yM;
	d_yM = i;
	//print("%d,%d,   %d,%d,  (%d)\n", d_xM , d_xm, d_yM , d_ym, size);
	if (d_xM - d_xm < (*s)->size && d_yM - d_ym < (*s)->size)
	{
		(*s)->size = (((d_xM - d_xm  < d_yM - d_ym) ? (d_yM - d_ym) : (d_xM - d_xm)));
		return ((int)size);
	}
	return (-1);
}

unsigned int	*concat(unsigned int *ref, unsigned int *item, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		ref[i] = item[i] | ref[i];
		i++;
	}
	return (ref);
}

unsigned int	*reset(unsigned int *ref, unsigned int *item, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ref[i] = (~item[i] & ref[i]);
		i++;
	}
	return (ref);
}

int		verification(unsigned int *ref, unsigned int *item, unsigned int size)
{
	unsigned int	n;

	n = 0;
	if (item[size] != 0)
		return (-2);
	while (n < size)
	{
		if ((signed)(item[n] << 1) >= (1 << (size + 1)))
		{
			return ((item[size - 1]) ? (-2) : (0));
		}
		if (ref[n] & item[n])
		{
			return (-1);
		}
		n++;
	}
	return (1);
}
/*

int		move_delta(unsigned int *item, unsigned int *ref, unsigned int size)
{
	unsigned int	i = 0;
	
	while (i < size)
		i++;
	return (0);
}*/

int		v3(t_tetrinoid **mat, int bool, unsigned int *ref, t_solution *s)
{
	t_tetrinoid	*tmp;
	int		verif;
	int		ret;

	ret = -1;
	if (*mat)
	{
		tmp = (*mat);
		while (move_item(ref, s->size, tmp->mat, bool) == 1)
		{
			ref = concat(ref, tmp->mat, s->size);
			verif = v3(mat + 1, 1, ref, s);
			if(verif >= 0)
			{
				ret = 0;
				leave_solution(verif ?((unsigned)verif) : (s->size),s, tmp);
				build_solution(s->size,s, tmp);
			}
			if (verif > 0)
				ref = reset(ref, tmp->mat, verif);
			else
				ref = reset(ref, tmp->mat, s->size);
			bool = 1;
		}
		return (ret);
	}
	else if (s)
	{
		return (solution(s->size, ref , &s));
	}
	return (-1);
}
