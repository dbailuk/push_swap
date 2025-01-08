/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:35 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/08 12:30:21 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	main(int ac, char **av)
{
	t_swap	*tab;

	if (ac < 2)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (1);
	tab->stack_a = parse_args(ac, av);
	if (!tab->stack_a)
	{
		free(tab);
		print_error_and_exit();
	}
	tab->stack_b = NULL;
	tab->asize = list_size(tab->stack_a);
	tab->bsize = 0;
	add_index(tab->stack_a);
	check_sort(tab);
	free_list(tab->stack_a);
	free_list(tab->stack_b);
	free(tab);
	return (0);
}
