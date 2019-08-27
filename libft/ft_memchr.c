/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:32:02 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 11:26:44 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a memory bank and an int and a length. scans
** through the memory until it finds the specified int, or
** it reaches the specified length. Returns a pointer to
** the found character or returns a null pointer.
** Uses: no libft functions.
*/

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		character;
	size_t				i;
	void				*nlptr;
	unsigned char		*src_ptr;

	src_ptr = (unsigned char*)s;
	nlptr = NULL;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src_ptr[i] == character)
		{
			nlptr = (void*)&src_ptr[i];
			return (nlptr);
		}
		i++;
	}
	return (nlptr);
}
