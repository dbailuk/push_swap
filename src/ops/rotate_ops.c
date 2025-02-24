/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:11 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:37:12 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rot(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = list_last(*stack);
	last->next = first;
}

void	ra(t_list **a)
{
	rot(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rot(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rot(a);
	rot(b);
	write(1, "rr\n", 3);
}
