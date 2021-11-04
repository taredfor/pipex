/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:48:58 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:48:59 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, int (*del)(int))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		del(lst->value);
		free(lst);
	}
	lst = NULL;
}
