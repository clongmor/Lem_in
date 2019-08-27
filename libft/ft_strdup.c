/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:43:28 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 10:56:46 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string, allocates enough memory
** for a copy of the string, does the copy and null
** terminates the copy. returns the copy.
** Uses: ft_strlen & malloc.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	len;

	len = (size_t)ft_strlen(s1);
	i = 0;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	if (s2[i - 1] != '\0')
		s2[i] = '\0';
	return (s2);
}
