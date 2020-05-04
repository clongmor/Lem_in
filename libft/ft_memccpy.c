/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:24:45 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 14:40:42 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in 2 banks of memory and an int and copies from source
** to destination until it finds the specified character, or
** until it reaches the length specified, whichever comes first.
** Uses: ft_memcpy
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	character;
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ft_memcpy((dst_ptr + i), (src_ptr + i), 1);
		if (src_ptr[i] == character)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
