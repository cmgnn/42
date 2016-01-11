/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_solution	*init_solution(unsigned int size)
{
	t_solution	*s;

	if ((s = (t_solution*)malloc(sizeof(t_solution))) != NULL)
	{
		s->size = size;
		ft_memset(s->buffer, '.', 10000000);
	}
	return (s);
}

t_tetrinoid	*init_tetrinoid(unsigned int *mat, char c)
{
	t_tetrinoid	*t;

	if ((t = malloc(sizeof(t_tetrinoid))) != NULL)
	{
		t->c = c;
		if (mat)
			ft_memcpy(t->mat, mat, 4);
	}
	return (t);
}

void		free_tetrinoid(t_tetrinoid *t)
{
	free(t->mat);
	free(t);
}
