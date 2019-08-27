/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:54:48 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:42:10 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string and reverses the string
** by swopping two character at a time. returns the string.
** Uses: ft_strlen.
*/

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s == NULL)
		return (NULL);
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}
