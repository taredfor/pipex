/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_ind_of_max_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:49:03 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 17:10:33 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_ind_of_max_value(t_list *lst)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = lst->value;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if (lst->value > max_value)
		{
			max_ind = it;
			max_value = lst->value;
		}
		lst = lst->next;
		it++;
	}
	return (max_ind);
}
