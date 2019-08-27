/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:19:39 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 12:15:26 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings, and allocates memory
** for the size of the two added together + \0. copies s1
** into the memory and then copies s2 in starting at the
** end of s1 using memcpy. returns the new string created.
** Uses: ft_memcpy, ft_strlen && malloc
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(join_str = (char *)malloc((len1 + len2) + 1)))
		return (NULL);
	while (i < len1)
	{
		join_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		join_str[i + len1] = s2[i];
		i++;
	}
	join_str[len1 + len2] = '\0';
	return (join_str);
}
