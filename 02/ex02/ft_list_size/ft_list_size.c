#include "ft_list.h"

int	ft_list_size(t_list *begin_list) {
	int 	i;
	t_list	*lst;

	i = 0;
	lst = begin_list;
	while (lst) {
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
int	ft_list_size(t_list *begin_list) {
	return !begin_list ? (0) : (1 + ft_list_size(begin_list->next));
}
*/