/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:48:54 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:48:55 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, int (*del)(int))
{
	t_list	*mem;

	if (!lst || !del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			mem = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = mem;
		}
	}
}
