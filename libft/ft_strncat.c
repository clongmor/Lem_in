/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:42:29 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 13:27:47 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and a length. It
** copies s2 into s1, starting at the \0 of s1, and
** only copies n characters. returns the concatenated
** string.
** Uses: ft_strlen, ft_memcpy
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	len2;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n >= len2)
		n = len2;
	ft_memcpy((s1 + len), s2, n);
	if (s1[len + n - 1] != '\0')
		s1[len + n] = '\0';
	return (s1);
}
