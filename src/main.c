/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:35 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:37:36 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_swap	*tab;

	if (ac < 2)
		return (0);
	tab = (t_swap *)malloc(sizeof(t_swap));
	if (!tab)
		return (1);
	tab->stack_a = parse_args(ac, av);
	if (!tab->stack_a)
	{
		free(tab);
		return (1);
	}
	tab->stack_b = NULL;
	tab->asize = list_size(tab->stack_a);
	tab->bsize = 0;
	add_index(tab->stack_a);
	check_sort(tab);
	return (0);
}
