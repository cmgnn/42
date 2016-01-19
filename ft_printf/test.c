#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	v = 10;
	char *ptr = "0123456789";
	double	f = 3000.00014;

	printf("%-05%\n");
	ft_printf("<%-05%>\n");

	printf("%X\n", v);
	ft_printf("<%X>\n", v);

	printf("%f\n", f);
	ft_printf("<%f>\n", f);

	printf("%c\n", *ptr);
	ft_printf("<%c>\n", *ptr);

	printf("%s\n", ptr);
	ft_printf("<%s>\n", ptr);

	printf("%%   %\n");
	ft_printf("<%%   %>\n");

	printf("%p\n", ptr);
	ft_printf("<%p>\n", ptr);

}