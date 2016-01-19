#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

# define BASE_BIN		"01"
# define BASE_OCT		"01234567"
# define BASE_DEC		"0123456789"
# define BASE_HEX_MIN	"0123456789abcdef"
# define BASE_HEX_MAJ	"0123456789ABCDEF"

int		printchar(const char c);
int		printstr(const char *s);
int		ft_putlong_base(long long nb, char *base);
int		ft_putdouble_base(double d, int prec, char *base);

#endif