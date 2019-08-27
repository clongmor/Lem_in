/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:31:17 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 13:18:44 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a double pointer to a list and a function that deletes
** a node's contents. it then loops through the list starting at
** the supplied link and deleted the node contents, frees its
** memory and moves onto the next node. returns nothing.
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		(*alst) = (*alst)->next;
		free(tmp);
	}
}
