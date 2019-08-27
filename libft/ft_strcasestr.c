/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:46:27 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 09:19:57 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and checks if
** needle is in haystack, but ignores the case of
** both needle and haystack by converting everything
** to lowercase in temp string copies. it then does
** the comparisons and returns an index where needle
** is found (or -1). the pointer is then set to the
** index in the orginal string and returned (or NULL).
** Uses: 1x static function, ft_strlen, ft_strncmp,
** ft_strdup, ft_strlowcase && malloc && free
*/

#include "libft.h"

static size_t	ft_compare(const char *haystack, const char *needle, size_t len)
{
	int				i;
	size_t			k;
	size_t			store;

	i = -1;
	k = 0;
	while (++i < (int)ft_strlen(haystack) && i < (int)len)
	{
		if (haystack[i] != needle[k])
			continue;
		store = i;
		while (haystack[i] == needle[k] && i < (int)len && (k = k + 1))
		{
			i++;
			if (needle[k] == '\0')
				return (store);
		}
		k = 0;
		i = store + 1;
	}
	return (-1);
}

char			*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t		len;
	char		*haystack2;
	char		*needle2;
	int			i;
	void		*nlptr;

	if (*needle == '\0' || ft_strncmp(needle, "", 1) == 0)
		return ((char *)haystack);
	haystack2 = ft_strdup(haystack);
	haystack2 = ft_strlowcase(haystack2);
	needle2 = ft_strdup(needle);
	needle2 = ft_strlowcase(needle2);
	len = ft_strlen(haystack2);
	i = ft_compare(haystack2, needle2, len);
	if (i != -1)
	{
		nlptr = (void *)&haystack[i];
		free(haystack2);
		free(needle2);
		return (nlptr);
	}
	free(haystack2);
	free(needle2);
	return (NULL);
}
