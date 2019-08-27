/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:37:53 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 15:42:03 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and checks if its in the normal
** ascii range, and then checks if it is a digit
** character or an alphabet character. returns 0
** for not true and 1 for true.
** Uses: ft_isalpha, ft_isdigit
*/

#include "libft.h"

int		ft_isalnum(int c)
{
	unsigned char character;

	character = (unsigned char)c;
	if (c > 255 || c < 0)
		return (0);
	if (ft_isalpha(character) != 0 || ft_isdigit(character) != 0)
		return (1);
	return (0);
}
