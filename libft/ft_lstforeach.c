#include "implemtlist.h"

void	ft_lstforeach(t_list *lst, void (*fct)())
{
	while (lst)
	{
		(*fct)(lst->content);
		lst = lst->next;
	}
}