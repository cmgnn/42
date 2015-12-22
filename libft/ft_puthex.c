/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.char                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 09:53:57 by fjacquem          #+#    #+#             */
/*   Updated: 2014/07/05 09:55:10 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_puthex_rec(unsigned long long number)
{
	char	c;
	char	*map;

	map = "0123456789ABCDEF";
	if (number)
	{
		c = (char)(number & 0xF);
		number = (number >> 4);
		ft_puthex_rec(number);
		ft_putchar(map[(int)c]);
	}
}

void			ft_puthex(unsigned long long number)
{
	ft_putstr("0x");
	ft_puthex_rec(number);
}
