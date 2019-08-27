/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:50:59 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 12:19:28 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and a length.
** copies from source to destination, until it reaches
** the end of source or the length specified, whichever
** comes first. if source is shorter than length, it
** fills the rest of dest with \0. Returns destination.
** Uses: ft_strlen, ft_memcpy.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	slen;
	char	*dst_ptr;

	dst_ptr = dst;
	slen = (size_t)ft_strlen(src);
	if (len <= slen)
	{
		ft_memcpy(dst_ptr, src, len);
		dst = dst_ptr;
		return (dst);
	}
	else
		ft_memcpy(dst_ptr, src, slen);
	while (slen < len)
	{
		dst_ptr[slen] = '\0';
		slen++;
	}
	dst = dst_ptr;
	return (dst);
}
