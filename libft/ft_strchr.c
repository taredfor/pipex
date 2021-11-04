/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:50:58 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:50:59 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*((unsigned char *)str + i) == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)(str + i));
	return (0);
}
