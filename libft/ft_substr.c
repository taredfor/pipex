/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:51:51 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:51:52 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < (start + len))
		mem = malloc(sizeof(char) * ft_strlen(s) - start + 1);
	else
		mem = malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (0);
	while (*(s + start) && i < len)
	{
		mem[i++] = s[start++];
	}
	mem[i] = '\0';
	return (mem);
}
