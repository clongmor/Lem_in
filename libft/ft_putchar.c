/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:40:16 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 15:00:04 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a character and writes it to the standard output.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
