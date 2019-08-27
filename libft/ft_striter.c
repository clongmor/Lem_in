/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:03:42 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/20 08:12:35 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a string and a function which takes a string.
** iterates through the characters of the string and
** applies the function parameter to each of the
** characters. Returns nothing.
** Uses: no libft functions
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	if (s == NULL || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(&s[i]);
		i++;
	}
}
