/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:10:14 by fjacquem          #+#    #+#             */
/*   Updated: 2015/11/24 13:10:16 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *begin;

	tmp = (t_list*)ft_memalloc(sizeof(t_list));
	begin = tmp;
	if (f && lst)
	{
		while (lst)
		{
			tmp = (*f)(lst);
			if (!tmp)
				return (NULL);
			lst = lst->next;
			tmp = tmp->next;
		}
	}
	return (begin);
}
