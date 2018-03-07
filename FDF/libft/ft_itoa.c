/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:33:00 by siosif            #+#    #+#             */
/*   Updated: 2017/12/19 16:49:44 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchars(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		counter++;
	}
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		i;
	long	ln;

	ln = (long)n;
	i = countchars(n);
	p = ft_strnew(i);
	if (!p)
		return (NULL);
	if (ln < 0)
	{
		ln *= -1;
		p[0] = '-';
	}
	if (ln == 0)
		p[i - 1] = '0';
	while (ln > 0)
	{
		p[i - 1] = '0' + ln % 10;
		i--;
		ln /= 10;
	}
	return (p);
}
