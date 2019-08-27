/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 08:30:48 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/20 09:05:45 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string and a function which
** takes an unsigned int and a character. it allocates
** memory for the size of the string + \0. it then
** applies to function to the string character by character
** and stores the characters in the allocated memory.
** returns the newly changed string.
** Uses: ft_strlen
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (s == NULL || !f)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		new_str[i] = (*f)(i, (char)s[i]);
		i++;
	}
	if (new_str[i] != '\0')
		new_str[i] = '\0';
	return (new_str);
}
