/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:43 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:56:53 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	first_partition(t_list **a, t_list **b, t_push *p, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if ((*a)->index <= p->mid)
			pb(a, b);
		else if (list_size(*b) > 1 && (*b)->index < (p->mid / 2))
			rr(a, b);
		else
			ra(a);
		i++;
	}
	p->max = p->mid;
	p->mid = (p->max - p->next) / 2 + p->next;
	p->flag++;
}

void	find_next(t_list **a, t_list **b, t_push *p)
{
	if (*b && (*b)->index == p->next)
		pa(a, b);
	else if ((*a)->index == p->next)
	{
		(*a)->flag = -1;
		ra(a);
		p->next++;
	}
	else if (*b && list_size(*b) > 2 && check_b_conditions(a, b, p))
		;
	else
		return ;
	find_next(a, b, p);
}

static void	partition_step(t_list **a, t_list **b, t_push *p)
{
	if (!(*b) || !list_size(*b))
		handle_empty_b(a, b, p);
	else
		handle_nonempty_b(a, b, p);
	p->mid = (p->max - p->next) / 2 + p->next;
	p->flag++;
}

void	quick_sort(t_list **a, t_list **b, int count)
{
	t_push	p;
	t_list	*mn;
	t_list	*mx;

	mn = find_min_lst(a);
	mx = find_max_lst(a);
	p.next = mn->index;
	p.max = mx->index;
	p.mid = (p.max - p.next) / 2 + p.next;
	p.flag = 0;
	first_partition(a, b, &p, count);
	while (!check_sorting_a(a, count))
		partition_step(a, b, &p);
}
