/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:52:11 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:52:13 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		usage(void)
{
	ft_putendl("\n============== __ L I B F T __ ==============\n");
	ft_putendl("---------------< print usage >---------------\n");
	ft_putendl("\n Format\t| coresp_type\n");
	ft_putendl("\n %d\t| integer");
	ft_putendl("\n %c\t| character");
	ft_putendl("\n %s\t| string");
	ft_putendl("\n %lf\t| double");
	ft_putendl("\n %b\t| bin");
	ft_putendl("\n %o\t| octal");
	ft_putendl("\n %h\t| hexa");
	ft_putstr("\n(with %b, %o or %h format, add <B>");
	ft_putstr(" character to write an unsigned integer)\n\n");
}

static	void	tri_i(const char *str, __builtin_va_list l)
{
	if (*str == 'd')
		ft_putnbr(__builtin_va_arg(l, int));
	else if (*str == 'c')
		ft_putchar(__builtin_va_arg(l, int));
	else if (*str == 's')
		ft_putstr(__builtin_va_arg(l, char*));
	else if (*str == 'l' && *(str + 1) == 'f')
	{
		ft_putdouble(__builtin_va_arg(l, double));
		str++;
	}
	else
		return (1);
	return (0);
}

static	int		tri_ii(const char *str, __builtin_va_list l)
{
	if (*str == 'b' && *(str + 1) == 'B')
	{
		ft_putnbr_base(__builtin_va_arg(l, int), BASE_BIN);
		str++;
	}
	else if (*str == 'o' && *(str + 1) == 'B')
	{
		ft_putnbr_base(__builtin_va_arg(l, int), BASE_OCT);
		str++;
	}
	else if (*str == 'h' && *(str + 1) == 'B')
	{
		ft_putnbr_base(__builtin_va_arg(l, int), BASE_HEX);
		str++;
	}
	else if (*str == 'b' || *str == 'o' || *str == 'h')
		ft_puthex(__builtin_va_arg(l, unsigned int));
	else
	{
		usage();
		return (1);
	}
	return (0);
}

void			ft_print(const char *str, ...)
{
	__builtin_va_list l;

	__builtin_va_start(l, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (tri_i(str++, l) && tri_ii(str++, l))
				break ;
		}
		else
			write(1, str, 1);
		str++;
	}
	__builtin_va_end(l);
}
