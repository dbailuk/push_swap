/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:27:54 by dbailuk           #+#    #+#             */
/*   Updated: 2024/06/20 18:22:47 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p++ = 0;
	}
}

/*int	main()
{
	char	buffer[5];
	int		i;

	i = 0;
	while (i < 5)
	{
		buffer[i] = 'D';
		i++;
	}

	ft_bzero(buffer, 5);
	i = 0;
	while (i < 5)
	{
		printf("%c ", buffer[i]);
		i++;
	}
	return (0);
}*/
