#include "../push_swap.h"

int	check_sorting(t_list **stack)
{
	t_list	*tmp = *stack;

	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_sorting_a(t_list **stack, int count)
{
	if (list_size(*stack) != count)
		return (0);
	return (check_sorting(stack));
}

t_list	*find_min_lst(t_list **stack)
{
	t_list	*tmp = *stack;
	t_list	*min = tmp;

	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_max_lst(t_list **stack)
{
	t_list	*tmp = *stack;
	t_list	*max = tmp;

	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	isrevsorted(t_swap *tab)
{
	t_list	*tmp = tab->stack_a;

	while (tmp && tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_sort(t_swap *tab)
{
	int	len = list_size(tab->stack_a);

	if (check_sorting(&tab->stack_a))
		return ;
	if (len == 2)
		sort_2(&tab->stack_a);
	else if (len == 3)
		sort_3nbr(tab);
	else if (len == 5)
		sort_5nbr(tab);
	else
		quick_sort(&tab->stack_a, &tab->stack_b, len);
}
