/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:44:29 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/20 08:19:52 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a string and a function which takes a
** character as input. It allocates memory the size
** of the string and then applies the function to
** the string character by character and stores it
** in the new memory allocated. returns the new string.
** Uses: ft_strlen && malloc
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	i;

	if (s == NULL || !f)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		new_str[i] = (*f)((char)(s[i]));
		i++;
	}
	new_str[ft_strlen(s)] = '\0';
	return (new_str);
}
