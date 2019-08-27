/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:13:20 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 10:51:03 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an integer, checks if its zero, if not checks
** the conditions and recursively calls the function till
** it reaches an int smaller than 10 and then breaks out
** and puts the numbers to the output. returns nothing.
** Uses: ft_putchar, ft_putnbr, ft_putstr.
*/

#include "libft.h"

void	ft_putnbr(int n)
{
	int		i;

	i = n;
	if (i == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 0)
		write(1, "0", 1);
	else if (i < 0)
	{
		ft_putchar('-');
		ft_putnbr(-i);
	}
	else if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}
