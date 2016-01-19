#include "ft_printf.h"

size_t		ft_strlen(const char *s)
{
	return (*s) ? (ft_strlen(s + 1) + 1) : (0);
}

int		printchar(const char c)
{
	write(1, &c, 1);
	return (c != 0);
}

int		printstr(const char *s)
{
	write(1, s, 1);
	if (*s)
		return(printstr(s + 1) + 1);
	return(0);
}

int		ft_putlong_base(long long nb, char *base)
{
	int length;
	int	ret;

	ret = 0;
	length = ft_strlen(base);
	if (length > 0)
	{
		if (nb < 0)
		{
			if (length + 1 == 10)
				write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= length)
		{
			ret += ft_putnbr_base(nb / length, base);
			ret += ft_putnbr_base(nb % length, base);
		}
		else
		{
			write(1, &base[nb], 1);
			return (1);
		}
	}
	return (ret);
}

int	ft_putdouble_base(double d, int prec, char *base)
{
	int		i;
	int		len;

	i = 0;
	len = ft_putnbr_base((int)d, base) + 1;
	printchar('.');
	d -= (int)d;
	while (i++ < prec)
	{
		d *= 10;
		if ((int)d == 0)
		{
			printchar('0');
			len++;
		}
	}
	return ft_putnbr_base((int)d, BASE_DEC) + len;
}