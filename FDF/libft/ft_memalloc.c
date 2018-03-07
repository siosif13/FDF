/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:59:06 by siosif            #+#    #+#             */
/*   Updated: 2017/12/19 16:46:53 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*c;

	i = 0;
	if ((c = (char *)malloc(sizeof(*c) * size)))
	{
		while (i < size)
		{
			c[i] = 0;
			i++;
		}
		return ((void *)c);
	}
	return (NULL);
}
