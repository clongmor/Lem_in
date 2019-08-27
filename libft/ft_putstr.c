/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:42:47 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 10:44:51 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string and loops through
** it using putchar to write each character to the
** standard output. return nothing.
** Uses: ft_putchar
*/

#include "libft.h"

void	ft_putstr(char const *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		ft_putchar(c[i]);
		i++;
	}
}
