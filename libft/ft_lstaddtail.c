/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:42:58 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/03 10:38:12 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtail(t_list **lst, t_list *elem)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(elem) || !(*lst))
		return ;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = elem;
	*lst = tmp;
}
