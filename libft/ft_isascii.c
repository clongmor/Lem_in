/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:38:11 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 15:45:00 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and checks if it is a valid ascii,
** code for a character. returns 0 for false and 1 for
** true.
** Uses: no libft functions
*/

#include "libft.h"

int		ft_isascii(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (c < 0 || c > 127)
		return (0);
	else
		return (1);
}
