#include "implemtlist.h"

int	ft_lstsize(t_list *lst)
{
	return ((lst)?(ft_lstsize(lst->next) + 1) : (0));
}