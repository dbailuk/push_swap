/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:39 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/04 15:37:40 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid(const char *s)
{
	int	i = 0;

	if ((s[0] == '-' || s[0] == '+') && s[1])
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	dup_check(t_list *lst, int val)
{
	while (lst)
	{
		if (lst->content == val)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*parse_args(int ac, char **av)
{
	t_list	*head = NULL;
	t_list	*node;
	long	num;
	int		i = 1;

	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (list_clear(&head), NULL);
		num = atol(av[i]);
		if (num > INT_MAX || num < INT_MIN || dup_check(head, (int)num))
			return (list_clear(&head), NULL);
		node = list_new((int)num);
		if (!node)
			return (list_clear(&head), NULL);
		list_add_back(&head, node);
		i++;
	}
	return (head);
}
