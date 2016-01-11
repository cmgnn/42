/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			build_solution(t_octet size, t_solution *s, t_tetrinoid *item)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (((1 << j) & item->mat[i]) >> j)
				s->buffer[i + j * size] = (item->c);
			j++;
		}
		i++;
	}
}

void			leave_solution(t_octet size, t_solution *s, t_tetrinoid *item)
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

t_octet			*reset_item(t_octet size, t_octet *item, int flag)
{
	unsigned int	n;
	int				bool;

	n = 0;
	bool = 0;
	while (!bool)
	{
		n = 0;
		while (n < size && !(item[n] != 0 && item[n] % 2 == 1))
			n++;
		if (item[n] % 2 == 1)
			bool = 1;
		n = 0;
		while (!bool && n < size)
		{
			item[n] = item[n] >> 1;
			n++;
		}
	}
	if (flag && !item[0])
	{
		n = 0;
		while (n < size && !item[n])
			n++;
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

int				v4(t_tetrinoid **mat, t_octet *item, t_octet *ref, t_solution *s)
{
	t_tetrinoid	*tmp;
	int		verif;
	int		ret;
	int		bool = 0;
	ret = -1;
	//print_tab(ref, s->size, 0);
	if (*mat)
	{
		tmp = (*mat);
		while (move_item(ref, s->size, tmp->mat, bool) == 1)
		{
			verif = v4(mat + 1, item, concat(ref, tmp->mat, s->size), s);
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

int				v3(t_tetrinoid **mat, int bool, t_octet *ref, t_solution *s)
{
	t_tetrinoid	*tmp;
	int			verif;
	int			ret;

	if (*mat)
	{
		tmp = (*mat);
		while (move_item(ref, s->size, tmp->mat, bool) == 1)
		{
			ref = concat(ref, tmp->mat, s->size);
			verif = v3(mat + 1, 1, ref, s);
			if (verif >= 0)
			{
				ret = 0;
				leave_solution(verif ? ((unsigned)verif) : (s->size), s, tmp);
				build_solution(s->size, s, tmp);
			}
			ref = reset(ref, tmp->mat, (verif > 0) ? verif : s->size);
			bool = 1;
		}
		return (ret);
	}
	else if (s)
		return (solution(s->size, ref, &s));
	return (-1);
}
