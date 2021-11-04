/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindmin_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:49:17 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:57:44 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfindmin_val(t_list *lst)
{
	int	min_value;

	min_value = lst->value;
	while (lst)
	{
		if (min_value > lst->value)
			min_value = lst->value;
		lst = lst->next;
	}
	return (min_value);
}
