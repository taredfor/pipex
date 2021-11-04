/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:51:28 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:51:29 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rez;

	if (!s)
		return (0);
	rez = ft_strdup(s);
	if (!rez)
		return (0);
	i = 0;
	while (*(s + i))
	{
		rez[i] = f(i, s[i]);
		i++;
	}
	return (rez);
}
