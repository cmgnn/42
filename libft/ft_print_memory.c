/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:51:59 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:52:01 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int counter;
	unsigned int num_addr;

	counter = 0;
	num_addr = 0;
	while (size > num_addr && addr)
	{
		counter = 0;
		ft_putnbr(num_addr);
		ft_putstr(" : ");
		while (counter % 18 < 16)
		{
			ft_putnbr_base(*(unsigned char*)(addr + counter), BASE_HEX);
			ft_putnbr_base(*(unsigned char*)(addr + counter + 1), BASE_HEX);
			ft_putstr(" ");
			counter += 2;
		}
		ft_putnstr(addr, 16);
		addr += 16;
		num_addr += 16;
		write(1, "\n", 1);
	}
}
