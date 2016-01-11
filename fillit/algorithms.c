/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_octet			bits_fort(t_octet value, t_octet n)
{
	if (value && n)
		return ((1 << n) & value) ? (n) : bits_fort(value, n - 1);
	return (0);
}

t_octet			bits_faible(t_octet value, t_octet n)
{
	return ((1 << n) & value) ? (n) : bits_faible(value, n + 1);
}

int				solution(t_octet size, t_octet *ref, t_solution **s)
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

int				verification(t_octet *ref, t_octet *item, t_octet size)
{
	t_octet	n;

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
