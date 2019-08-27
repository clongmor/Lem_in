/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:04:05 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 12:08:06 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and using memcpy,
** it copies the whole string from source to destination.
** it returns the destination string.
** Uses: ft_strlen, ft_memcpy
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	n;

	n = ((size_t)ft_strlen(src) + 1);
	ft_memcpy(dst, src, n);
	return (dst);
}
