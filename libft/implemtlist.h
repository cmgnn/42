#ifndef	IMPLEMTLIST_H
# define IMPLEMTLIST_H
# ifndef ITERATIV_METHOD
#  define RECURSIF_METHOD
# endif
# include "list.h"
int	ft_lstsize(t_list *lst);
void	ft_lstforeach(t_list *lst, void (*fct)());
#endif