/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:06:50 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:39:29 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to a string and a length. it then
** mallocs memory for the length supplied or the length of
** the string, whichever is shorter. then it does the copy
** into the new memory, up to n characters copied, and null
** temrinates. Returns the copy of the string.
** Uses: ft_strlen && malloc.
*/

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	if (n < (size_t)(ft_strlen(s1) + 1))
		len = n;
	else
		len = ft_strlen(s1);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < (size_t)len)
	{
		s2[i] = s1[i];
		i++;
	}
	if (s2[i - 1] != '\0')
		s2[i] = '\0';
	return (s2);
}
