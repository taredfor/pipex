/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:49:32 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 17:00:03 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int))
{
	t_list	*new;
	t_list	*temp;

	if (lst && f)
	{
		new = ft_lstnew((f(lst->value)));
		temp = new;
		lst = lst->next;
		while (lst)
		{
			new = ft_lstnew((f(lst->value)));
			if (!new)
			{
				ft_lstclear(&new, del);
				return (0);
			}
			lst = lst->next;
			ft_lstadd_back(&temp, new);
		}
		return (temp);
	}
	return (0);
}
