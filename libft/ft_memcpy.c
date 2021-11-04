/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:50:00 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:50:01 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*sf;
	char		*db;
	size_t		i;

	db = dst;
	sf = src;
	i = 0;
	if (db == 0 && sf == 0)
		return (0);
	while (i < n)
	{
		*((unsigned char *)(db + i)) = *((unsigned char *)(sf + i));
		i++;
	}
	return (db);
}
