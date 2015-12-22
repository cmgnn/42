/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int n;
	int bool;

	n = 0;
	bool = 0;
	if (*str == '-')
	{
		str++;
		bool = 1;
	}
	while (*str == '0')
	{
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		n *= 10;
		n += *(str++) - '0';
	}
	if (bool)
		n = -n;
	return (n);
}
