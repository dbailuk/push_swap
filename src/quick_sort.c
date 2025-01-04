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



static void find_next(t_list **a, t_list **b, t_push *p)
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
	int	sz_b;
	int	i;
	int	f;

	if (!(*b) || list_size(*b) == 0)
	{
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
	else
	{
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
