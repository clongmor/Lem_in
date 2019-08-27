/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:37:02 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 14:40:22 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and a length. if
** needle is empty, returns haystack. Otherwise searches
** for needle in haystack(up to n characters of haystack
** at maxmimum and returns a pointer to the
** first character of the located string in haystack, or
** a pointer to NULL if it is not there.
** Uses: ft_strncmp, ft_strlen
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	size_t			k;
	void			*nlptr;
	size_t			store;

	i = -1;
	k = 0;
	if (*needle == '\0' || ft_strncmp(needle, "", 1) == 0)
		return ((char*)haystack);
	while (++i < (int)ft_strlen(haystack) && i < (int)len)
	{
		if (haystack[i] != needle[k])
			continue;
		nlptr = (void*)&haystack[i];
		store = i;
		while (haystack[i] == needle[k] && i < (int)len && (k = k + 1))
		{
			i++;
			if (needle[k] == '\0')
				return (nlptr);
		}
		k = 0;
		i = store + 1;
	}
	return (NULL);
}
