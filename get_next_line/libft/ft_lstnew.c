/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:09:37 by fjacquem          #+#    #+#             */
/*   Updated: 2015/11/24 13:09:39 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = (t_list*)ft_memalloc(sizeof(t_list));
	if (lst)
	{
		lst->next = NULL;
		lst->content = (content_size) ? ((void*)content) : (NULL);
		lst->content_size = content_size;
	}
	return (lst);
}
