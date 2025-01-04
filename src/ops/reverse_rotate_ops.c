/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:07 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:37:08 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rrev(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a)
{
	rrev(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rrev(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rrev(a);
	rrev(b);
	write(1, "rrr\n", 4);
}
