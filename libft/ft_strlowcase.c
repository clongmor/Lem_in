/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:50:09 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:32:25 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string and checks character
** by character if any of the characters are upper case.
** if they are, it converts them to lowercase. returns
** the original string supplied all in lowercase.
** Uses: no libft functions
*/

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	str[i] = '\0';
	return (str);
}
