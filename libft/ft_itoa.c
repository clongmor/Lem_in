/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:32:38 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 10:57:40 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int and uses ft_intlength to count how many
** digits are in the int. it allocates memory for the size
** of the digits + \0 and sets it to \0. it checks if its
** a negative number and  makes it positive. then calls
** copypasta to convert the digits into characters one by
** one and adding them to the memory in reverse and return
** the string. the string is then reversed using ft_strrev
** and the new string is returned.
** Uses: 1x static function, ft_strrev, ft_intlength, ft_strdup, ft_strnew
*/

#include "libft.h"

static char		*ft_copypasta(char *str, long int new_int, int neg)
{
	int			i;

	i = 0;
	while (new_int > 0)
	{
		str[i++] = new_int % 10 + '0';
		new_int /= 10;
	}
	if (neg < 0)
		str[i] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			neg;
	long int	new_int;

	new_int = n;
	if (!(str = ft_strnew(ft_intlength(n))))
		return (NULL);
	neg = 1;
	if (new_int < 0)
	{
		neg = -1;
		new_int *= -1;
	}
	if (new_int == 0)
		return (ft_strdup("0"));
	str = ft_copypasta(str, new_int, neg);
	ft_strrev(str);
	return (str);
}
