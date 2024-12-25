#include "../push_swap.h"

static void reverse_rotate_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	if (stack->size < 2)
		return;
	current = stack->top;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
}

void rra(t_stack *a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
	reverse_rotate_stack(b);
		write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
