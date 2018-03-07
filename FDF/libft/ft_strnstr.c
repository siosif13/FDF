/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:37:45 by siosif            #+#    #+#             */
/*   Updated: 2017/12/19 16:44:52 by siosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int k;
	int s;

	if (!*little)
		return (char *)(big);
	i = 0;
	while (big[i] && len > 0)
	{
		if (len < ft_strlen(little))
			return (NULL);
		k = 0;
		s = i;
		while (big[s] == little[k] && little[k] && big[s])
		{
			k++;
			s++;
		}
		if (little[k] == '\0')
			return ((char *)big + i);
		len--;
		i++;
	}
	return (NULL);
}
