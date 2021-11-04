/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_for_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:46:24 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 14:35:46 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char str, int sign)
{
	if (str == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi_for_number(const char *str)
{
	unsigned int		i;
	long				temp;
	int					sign;

	i = 0;
	sign = 1;
	temp = 0;
	while ((8 < str[i] && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ft_sign(str[i++], sign);
	while (str[i])
	{
		if (48 > str[i] || str[i] > 57)
			ft_error("Error");
		temp = temp * 10 + str[i] - '0';
		i++;
	}
	temp *= sign;
	if (temp > 2147483647 || temp < -2147483648)
		ft_error ("Error");
	return (temp);
}
