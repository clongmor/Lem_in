/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:56:07 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 12:24:40 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a data for content and its size as a size_t. It then
** allocates memory the size of a t_list node and checks if the
** the content supiled is NULL. if it isn't, then allocates
** memory for the content according the specified content size
** and copies in the content, and adds the content size to the node.
** links the node to nothing and returns the new head node of a fresh list.
** Uses: ft_memalloc, ft_memcpy.c
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlist;

	nlist = (t_list *)ft_memalloc(sizeof(t_list));
	if (!(nlist))
		return (NULL);
	if (content == NULL)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		nlist->content = ft_memalloc(content_size);
		if (nlist->content == NULL)
			return (NULL);
		ft_memcpy(nlist->content, content, content_size);
		nlist->content_size = content_size;
	}
	nlist->next = NULL;
	return (nlist);
}
