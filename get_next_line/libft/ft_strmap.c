/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:18:24 by fjacquem          #+#    #+#             */
/*   Updated: 2015/11/24 10:18:26 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char *str;
	char *tmp;

	str = (char *)s;
	tmp = (char *)s;
	while (s && *s)
	{
		*(str++) = (*f)(*(s++));
	}
	return (tmp);
}
