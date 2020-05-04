/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:30:34 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:05:59 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an integer and checks if that int
** corresponds to a lowercase character in the
** alphabet. if true, returns 1, else returns
** false.
** Uses: no libft functions
*/

#include "libft.h"

int		ft_islower(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character >= 97 && character <= 122)
		return (1);
	return (0);
}
