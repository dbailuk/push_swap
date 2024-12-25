#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;
	t_node	*current;

	if (a->size < 2)
		return;
	temp = a->top;
	a->top = a->top->next;
	temp->next = NULL;
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*temp;
	t_node	*current;

	if (b->size < 2)
		return;
	temp = b->top;
	b->top = b->top->next;
	temp->next = NULL;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
	{
		t_node *temp = a->top;
		a->top = a->top->next;
		temp->next = NULL;
		t_node *current = a->top;
		while (current->next)
			current = current->next;
		current->next = temp;
	}
	if (b->size >= 2)
	{
		t_node *temp = b->top;
		b->top = b->top->next;
		temp->next = NULL;
		t_node *current = b->top;
		while (current->next)
			current = current->next;
		current->next = temp;
	}
	write(1, "rr\n", 3);
}
