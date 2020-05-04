/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:14:28 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 15:52:25 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and checks if it is a printable
** character, returns 0 for false and 1 for true.
** Uses: no libft functions
*/

#include "libft.h"

int		ft_isprint(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character < 32 || character > 126)
		return (0);
	return (1);
}
