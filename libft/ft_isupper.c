/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:10:33 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:08:49 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an integer and checks if it corresponds to
** an ascii number of an uppercase alphabet character.
** returns 1 if its true, otherwise 0.
** Uses: no libft functions
*/

#include "libft.h"

int		ft_isupper(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character >= 'A' && character <= 'Z')
		return (1);
	return (0);
}
