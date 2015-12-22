/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:09:21 by fjacquem          #+#    #+#             */
/*   Updated: 2015/11/24 13:09:23 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = new;
	tmp2 = *alst;
	if (alst && *alst && new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tmp2;
		*alst = new;
	}
}
