#include "../push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return;
	if (a->size <= 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		quick_sort(a, b, a->size);
}

static void handle_two(t_stack *a)
{
	int	f;
	int	s;

	f = a->top->value;
	s = a->top->next->value;
	if (f > s)
		sa(a);
}

static void handle_three(t_stack *a, int f, int s, int t)
{
	if (f > s && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > t && s < t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

void	sort_3(t_stack *a)
{
	t_node	*top;
	int		f;
	int		s;
	int		t;

	if (a->size < 2)
		return ;

	if (a->size == 2)
		return (handle_two(a));
	top = a->top;
	f = top->value;
	s = top->next->value;
	t = top->next->next->value;
	handle_three(a, f, s, t);
}
