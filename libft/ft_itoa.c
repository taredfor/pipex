/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:48:32 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:48:33 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		i++;
	}
	while (c)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{	
	int		j;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = ft_len(n);
	str = (char *)malloc(sizeof (char) * (j + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[j] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n)
	{
		j--;
		str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
