/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindmax_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:49:11 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:57:50 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfindmax_val(t_list *lst)
{
	int	max_value;

	max_value = lst->value;
	while (lst)
	{
		if (max_value < lst->value)
			max_value = lst->value;
		lst = lst->next;
	}
	return (max_value);
}
