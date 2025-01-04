/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:47 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:37:48 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	sort_3nbr(t_swap *tab)
{
	t_list	*last = list_last(tab->stack_a);

	if (check_sorting(&tab->stack_a))
		return ;
	if (isrevsorted(tab))
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content < last->content)
		sa(&tab->stack_a);
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content < last->content)
		ra(&tab->stack_a);
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content > last->content)
	{
		sa(&tab->stack_a);
		ra(&tab->stack_a);
	}
	else
		rra(&tab->stack_a);
}

void	sort_5nbr(t_swap *tab)
{
	int	len = list_size(tab->stack_a);

	while (len--)
	{
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			pb(&tab->stack_a, &tab->stack_b);
		else
			ra(&tab->stack_a);
	}
	sort_3nbr(tab);
	pa(&tab->stack_a, &tab->stack_b);
	pa(&tab->stack_a, &tab->stack_b);
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a);
}
