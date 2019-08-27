/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:02:16 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 15:19:47 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and checks if its ascii value is
** within the range of normal characters, then checks
** if it is true for isupper and islower. returns 1 for
** true and 0 for not true.
** Uses: ft_isupper, ft_islower
*/

#include "libft.h"

int		ft_isalpha(int c)
{
	unsigned char character;

	character = (unsigned char)c;
	if (c > 255 || c < 0)
		return (0);
	if (ft_isupper(character) != 0 || ft_islower(character) != 0)
		return (1);
	return (0);
}
