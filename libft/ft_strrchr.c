/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:51:44 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:51:45 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (*(str + i))
	{
		if (*(str + i) == (char)c)
			j = i;
		i++;
	}
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	if (j >= 0)
		return ((char *)(str + j));
	else if (j == -1)
		return (0);
	else
		return ((char *)(str + i));
}
