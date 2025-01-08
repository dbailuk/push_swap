/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:26 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/08 12:59:30 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*find_min_unindexed(t_list *lst)
{
	long	m;
	t_list	*min;

	if (!lst)
		print_error_and_exit();
	m = LONG_MAX;
	min = NULL;
	while (lst)
	{
		if (lst->index == -1 && lst->content < m)
		{
			m = lst->content;
			min = lst;
		}
		lst = lst->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	t_list	*min;
	int		i;
	int		size;

	size = list_size(lst);
	i = 0;
	while (i < size)
	{
		min = find_min_unindexed(lst);
		if (!min)
			return ;
		min->index = i;
		i++;
	}
}
