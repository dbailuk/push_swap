#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int value;
	if (b->size == 0)
		return;
	value = pop_stack(b);
	push_stack(a, value);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int value;
	if (a->size == 0)
		return;
	value = pop_stack(a);
	push_stack(b, value);
	write(1, "pb\n", 3);
}
