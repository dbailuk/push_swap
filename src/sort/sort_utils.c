#include "../push_swap.h"

/*
** check_sorting_a:
**   Returns 1 if:
**     - 'a' has exactly 'count' nodes
**     - 'a' is sorted in ascending order by index (or value)
*/
int	check_sorting_a(t_stack *a, int count)
{
	t_node	*tmp;
	int		i;

	// quick check: must have exactly 'count' elements
	if (a->size != count)
		return (0);

	// verify ascending order
	tmp = a->top;
	i = 0;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

/*
** find_min_index:
**   Returns the smallest 'index' found in stack 'a'.
*/
int	find_min_index(t_stack *a)
{
	t_node	*tmp;
	int		min_i;

	if (!a->top)
		return (0);
	tmp = a->top;
	min_i = tmp->index;
	while (tmp)
	{
		if (tmp->index < min_i)
			min_i = tmp->index;
		tmp = tmp->next;
	}
	return (min_i);
}

/*
** find_max_index:
**   Returns the largest 'index' found in stack 'a'.
*/
int	find_max_index(t_stack *a)
{
	t_node	*tmp;
	int		max_i;

	if (!a->top)
		return (0);
	tmp = a->top;
	max_i = tmp->index;
	while (tmp)
	{
		if (tmp->index > max_i)
			max_i = tmp->index;
		tmp = tmp->next;
	}
	return (max_i);
}
