/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:51:47 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:51:48 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		s;
	size_t		f;
	char		*str;
	size_t		i;

	if (!s1)
		return (0);
	f = ft_strlen (s1);
	s = 0;
	while (*(s1 + s) && ft_strchr(set, *(s1 + s)))
		s++;
	while (ft_strchr(set, *(s1 + f - 1)) && f > s)
		f--;
	str = (char *)malloc(sizeof (char) * (f - s + 1));
	if (!str)
		return (0);
	i = 0;
	while (s < f)
		*(str + i++) = *(s1 + s++);
	str[i] = '\0';
	return (str);
}
