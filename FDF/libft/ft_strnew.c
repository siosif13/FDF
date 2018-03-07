/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:33:15 by siosif            #+#    #+#             */
/*   Updated: 2017/12/19 16:47:27 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if ((p = (char *)malloc(sizeof(*p) * size + 1)))
	{
		while (i <= size)
		{
			p[i] = '\0';
			i++;
		}
		return (p);
	}
	return (NULL);
}