/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:39:26 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 10:20:18 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string, an index and a length,
** uses malloc to allocate memory for the specified length
** plus 1 for \0. it then copies from the start index of the
** string supplied for the length specified into the allocated
** memory string, and then null terminates. Returns the new string.
** Uses: malloc
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	sub_str = (char *)malloc((len * 1) + 1);
	if (sub_str == NULL)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	if (sub_str[i] != '\0')
		sub_str[i] = '\0';
	return (sub_str);
}
