#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	temp;
	if (a->size < 2)
		return;
	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;
	if (b->size < 2)
		return;
	temp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = temp;
	write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
	int	temp;
	if (a->size >= 2)
	{
		temp = a->top->value;
		a->top->value = a->top->next->value;
		a->top->next->value = temp;
	}
	if (b->size >= 2)
	{
		temp = b->top->value;
		b->top->value = b->top->next->value;
		b->top->next->value = temp;
	}
	write(1, "ss\n", 3);
}
