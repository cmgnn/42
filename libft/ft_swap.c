#include "implemt.h"

void	ft_swap(void *a, void *b)
{
	int	tmp;
	
	tmp = *((int*)a);
	*((int*)a) = *((int*)b);
	*((int*)b) = tmp;
}
