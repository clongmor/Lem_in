/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:38:11 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 14:23:46 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a list and a function to apply to nodes of a list.
** stores the function applied first node in a temp variable,
** creates a new node  using lstnew and stores that temp node's
** details in the first node and sets a pointer to mark the
** first node. then moves to the next node and loops though
** all the nodes in the supplied list. it then frees memory
** for the temp variables. and returns a pointer to the start
** of the newly created list.
** Uses: ft_lstnew && free.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;
	t_list	*first;

	if (lst == NULL || f == NULL)
		return (NULL);
	(tmp) = f(lst);
	if (!(first = (ft_lstnew((tmp)->content, (tmp)->content_size))))
		return (NULL);
	head = first;
	(lst) = (lst)->next;
	while (lst)
	{
		(tmp) = f(lst);
		if (!(first->next = (ft_lstnew((tmp)->content, (tmp)->content_size))))
			return (NULL);
		(first) = (first)->next;
		(lst) = (lst)->next;
	}
	free(first);
	return (head);
}
