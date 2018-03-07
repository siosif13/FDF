/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:42:50 by siosif            #+#    #+#             */
/*   Updated: 2017/12/19 16:43:14 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	x;

	x = (unsigned char)c;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n > 0 && *s != x)
	{
		n--;
		*d++ = *s++;
	}
	if (n > 0)
	{
		*d++ = *s++;
		return ((void *)d);
	}
	else
		return (NULL);
}
