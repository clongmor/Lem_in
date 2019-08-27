/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:17:31 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 16:11:06 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and checks if its lowercase.
** if it is lowercase, it changes it to uppercase.
** returns the character.
** Uses: no libft functions
*/

#include "libft.h"

int		ft_toupper(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (c < 97 || c > 122)
		return (c);
	if (character >= 'a' && character <= 'z')
		character = character - 32;
	return (character);
}
