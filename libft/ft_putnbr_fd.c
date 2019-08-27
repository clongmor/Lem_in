/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:35:42 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 12:15:04 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an int to display and an int for
** identifying which output to display it on.
** recursively calls itself until it reaches
** a number less than 10 and then it breaks
** out and displays the number on the specified
** output. returns nothing.
** Uses: ft_putstr_fd, ft_putchar_fd, ft_putnbr_fd
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;

	i = n;
	if (i == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 0)
		write(fd, "0", 1);
	else if (i < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-i, fd);
	}
	else if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
		ft_putchar_fd(i + '0', fd);
}
