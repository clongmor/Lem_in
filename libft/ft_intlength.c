/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:15:08 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:01:32 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an integer and checks if negative(negative counts
** as 1 string character). then divides the number by 10
** repeatedly so it can count the number of characters in the
** number. returns the counted characters.
** Uses: no libft functions.
*/

#include "libft.h"

int		ft_intlength(int n)
{
	int			count;
	long int	new_int;

	new_int = n;
	count = 0;
	if (new_int < 0)
	{
		new_int *= -1;
		count++;
	}
	while (new_int > 0)
	{
		new_int = new_int / 10;
		count++;
	}
	return (count);
}
