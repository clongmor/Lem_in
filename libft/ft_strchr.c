/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:11:04 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 10:42:07 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string and an int. searches
** through the string for the int and returns a pointer
** to the index of the string where it first finds the
** character.
** Uses: ft_strlen, ft_memchr
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		character;
	size_t				i;
	void				*nlptr;
	unsigned char		*src_ptr;
	size_t				n;

	n = ft_strlen(s) + 1;
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
