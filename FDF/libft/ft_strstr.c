/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:06:46 by siosif            #+#    #+#             */
/*   Updated: 2017/12/19 16:44:47 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*fp;
	const char	*b;
	const char	*l;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		b = big;
		l = little;
		if (*b == *l)
			fp = big;
		while (*b == *l && *l != '\0')
		{
			b++;
			l++;
		}
		if (*l == '\0')
			return ((char *)fp);
		big++;
	}
	return (NULL);
}
