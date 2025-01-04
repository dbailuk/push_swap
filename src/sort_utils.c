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

int	check_b_conditions(t_list **a, t_list **b, t_push *p)
{
	t_list	*lastb;

	lastb = list_last(*b);
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

void	handle_empty_b(t_list **a, t_list **b, t_push *p)
{
	int	f;

	f = (*a)->flag;
	while (*a && (*a)->flag == f && f != -1)
	{
		if ((*a)->index != p->next)
			pb(a, b);
		find_next(a, b, p);
	}
	if (*b)
		p->max = find_max_lst(b)->index;
}

void	handle_nonempty_b(t_list **a, t_list **b, t_push *p)
{
	int	sz_b;
	int	i;

	sz_b = list_size(*b);
	i = -1;
	while (++i < sz_b && list_size(*b))
	{
		if ((*b)->index == p->next)
			find_next(a, b, p);
		else if ((*b)->index >= p->mid)
		{
			(*b)->flag = p->flag;
			pa(a, b);
		}
		else
			rb(b);
	}
	p->max = p->mid;
}
