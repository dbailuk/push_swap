/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:17 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:37:18 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap_top(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
}
