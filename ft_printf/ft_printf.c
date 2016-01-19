#include "ft_printf.h"

static	int		tri_format(const char *str, __builtin_va_list l)
{
	if (*str == 'd' || *str == 'D' || *str == 'i')
		return ft_putlong_base(__builtin_va_arg(l, int), BASE_DEC);
	else if (*str == 'c' || *str == 'c')
		return printchar(__builtin_va_arg(l, int));
	else if (*str == 's' || *str == 'S')
		return printstr(__builtin_va_arg(l, char*));
	else if (*str == 'u' || *str == 'U')
		return ft_putlong_base(__builtin_va_arg(l, unsigned int), BASE_DEC);
	else if (*str == 'x' || *str == 'X' || *str == 'p' || *str == 'P')
	{
		printstr((*str == 'X' || *str == 'P') ? "0X" : "0x");
		return 2 + ft_putlong_base(__builtin_va_arg(l, unsigned int),
										(*str == 'X' || *str == 'P') ?
											BASE_HEX_MAJ : BASE_HEX_MIN);
	}else if (*str == 'o')
		return ft_putlong_base(__builtin_va_arg(l, int), BASE_OCT);
	else if (*str == 'b')
		return ft_putlong_base(__builtin_va_arg(l, int), BASE_BIN);
	else if (*str == 'f' || *str == 'F')
		ft_putdouble_base(__builtin_va_arg(l, double), 6, BASE_DEC);
	return (0);
}

static char	*tri_flag(char *str)
{
	int	mask = 0;
	while (*str == ' ' || *str == '+' || *str == '-' || *str == '0' || *str == '#')
	{
		if (*str == ' ')
		{
			write(1, " ", 1);
			mask |= 2;
		}
		if (*str == '-' && !(mask & 4))
			mask |= 4;
		if (*str == '+' && !(mask & 8))
			mask |= 8;
		if (*str == '+' && !(mask & 0))
			mask |= 0;
		if (*str == '-' && !(mask & 1))
			mask |= 1;
		str++;
	}
	return (str);
}

static char	*tri_prec(char *str, int *dec, int *fl)
{
	*dec = 0;
	if (*str >= '0' || *str <= '9')
	{
		*dec = ft_atoi(str);
	}
	if (*str == '.')
		*fl = ft_atoi(str + 1);
	return (str);
}

int			ft_printf(const char *str, ...)
{
	__builtin_va_list l;
	int	len;
	char *tmp;
	int	prec_dec;
	int	prec;

	__builtin_va_start(l, str);
	len = 0;
	tmp = (char*)str;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			tmp = tri_flag(tmp);
			tmp = tri_prec(tmp, &prec_dec, &prec);
			while (*tmp && (len += tri_format(tmp, l)) == 0 && *(++tmp) != '%')
				;
			if (*tmp == '%')
				write(1, tmp, 1);
		}
		else
			write(1, tmp, 1);
		tmp++;
	}
	__builtin_va_end(l);
	return (len);
}
