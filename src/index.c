#include "../push_swap.h"

static t_list	*find_min_unindexed(t_list *lst)
{
	long	m = LONG_MAX;
	t_list	*min = NULL;

	while (lst)
	{
		if (lst->index == -1 && lst->content < m)
		{
			m = lst->content;
			min = lst;
		}
		lst = lst->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	t_list	*min;
	int		i;
	int		size = list_size(lst);

	i = 0;
	while (i < size)
	{
		min = find_min_unindexed(lst);
		if (!min)
			return ;
		min->index = i;
		i++;
	}
}
