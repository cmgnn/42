#include "libft.h"

void	print(char *str, ...)
{
	__builtin_va_list l;

	__builtin_va_start(l, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
				ft_putnbr(__builtin_va_arg(l, int));
			else if (*str == 'c')
				ft_putchar( __builtin_va_arg(l, int));
			else if (*str == 's')
				ft_putstr(__builtin_va_arg(l, char*));
			else if (*str == 'l' && *(str + 1) == 'f')
			{
				ft_putdouble(__builtin_va_arg(l, double));
				str++;
			}
			else if (*str == 'B' && *(str + 1) == 'b')
			{
				ft_putnbr_base(__builtin_va_arg(l, int), BASE_BIN);
				str++;
			}
			else if (*str == 'B' && *(str + 1) == 'o')
			{
				ft_putnbr_base(__builtin_va_arg(l, int), BASE_OCT);
				str++;
			}
			else if (*str == 'B' && *(str + 1) == 'h')
			{
				ft_putnbr_base(__builtin_va_arg(l, int), BASE_HEX);
				str++;
			}
			else if (*str == 'b' || *str == 'o' || *str == 'h')
			{
				ft_puthex(__builtin_va_arg(l, unsigned long long));
			}
		}
		else
			write(1, str, 1);
		str++;
	}
	__builtin_va_end(l);
}
