/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:23:25 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 13:40:42 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to a string and an int, scans through
** the string in from last index to first and checks for the
** int. returns a pointer to the last occurrence of the int
** or NULL if its not found.
** Uses: ft_strncmp, ft_strlen
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	character;
	int				i;
	char			*nlptr;
	const char		*src_ptr;

	src_ptr = s;
	nlptr = NULL;
	character = (char)c;
	if (ft_strncmp(s, "", 1) == 0 && c == '\0')
	{
		nlptr = (char *)&src_ptr[0];
		return (nlptr);
	}
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (src_ptr[i] == character)
		{
			nlptr = (char*)&src_ptr[i];
			return (nlptr);
		}
		i--;
	}
	return (nlptr);
}
