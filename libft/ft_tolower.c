/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:47:03 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 16:54:40 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and checks if its uppercase.
** if it is, it changes it to lowercase.
** returns the character.
** Uses: no libft functions.
*/

#include "libft.h"

int		ft_tolower(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (c < 65 || c > 90)
		return (c);
	if (character >= 'A' && character <= 'Z')
		character = character + 32;
	return (character);
}
