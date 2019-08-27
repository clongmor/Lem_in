/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:41:05 by event             #+#    #+#             */
/*   Updated: 2019/07/04 10:23:26 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes a bank of memory and sets each byte to the provided int,
** for the length of the provided size_t. reads through \0 since
** not reading as a string. returns the pointer to memory area.
*/

#include "libft.h"

void	*ft_memset(void *ptr, int cbyte, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = ptr;
	while (i < len)
	{
		p[i] = (unsigned char)cbyte;
		i++;
	}
	ptr = p;
	return (ptr);
}
