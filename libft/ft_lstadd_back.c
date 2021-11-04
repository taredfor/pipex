/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:48:37 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:48:38 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*mem;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			mem = ft_lstlast(*lst);
			mem->next = new;
		}	
	}
}
