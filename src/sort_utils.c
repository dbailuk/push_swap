/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:00:05 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 16:18:49 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_min_lst(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *stack;
	min = tmp;
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
	t_list	*tmp;
	t_list	*max;

	tmp = *stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int check_b_conditions(t_list **a, t_list **b, t_push *p)
{
    t_list *lastb = list_last(*b);

    if (lastb->index == p->next)
        rrb(b);
    else if ((*a)->next && (*a)->next->index == p->next)
        sa(a);
    else if ((*a)->next && (*b)->next
        && (*a)->next->index == p->next
        && (*b)->next->index == p->next + 1)
        ss(a, b);
    else
        return (0);
    return (1);
}
