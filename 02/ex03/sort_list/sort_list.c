typedef struct      s_list
{
	struct s_list   *next;
	int            data;
}                   t_list;

t_list	*sort_list(t_list* lst, int (*cmp)(int, int)) {
	int	tmp;
	t_list *swap = lst;

	while (lst->next) {
		if (!(*cmp)(lst->data, lst->next->data)) {
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = swap;
		} else
			lst = lst->next;
	}
	lst = swap;
	return lst;
}