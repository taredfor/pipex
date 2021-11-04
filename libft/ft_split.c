/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:50:53 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:50:54 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**ft_free_mem(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	ft_number_str(char const *s, char c)
{
	int	i;
	int	num_slov;

	i = 0;
	num_slov = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && (s[i]))
			++num_slov;
		while (s[i] != c && s[i])
			i++;
	}
	return (num_slov);
}

static	char	**ft_copy(char **arr, char const *s, char c, int k)
{
	int	i;
	int	l;

	i = 0;
	while ((i < ft_number_str(s, c)) && (s[k]))
	{
		while (s[k] && s[k] == c)
			k++;
		l = 0;
		while (s[k] != c && s[k])
		{
			l++;
			k++;
		}
		arr[i] = malloc(sizeof(char) * (l + 1));
		if (!arr[i])
		{	
			ft_free_mem(&arr[i]);
			return (0);
		}
		ft_strlcpy(arr[i], s + k - l, l + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		num_slov;
	char	**mem;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	num_slov = ft_number_str(s, c);
	mem = malloc(sizeof(char *) * (num_slov + 1));
	if (!mem)
		return (0);
	return (ft_copy(mem, s, c, 0));
}
