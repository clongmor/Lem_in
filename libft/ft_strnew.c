/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:29:24 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 10:59:40 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a size, allocates a memory of that size,
** plus 1 for the \0. then sets each byte to \0.
** returns the memory block allocated.
** Uses: ft_memalloc.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*mem_area;
	size_t			i;

	if (!(mem_area = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		mem_area[i] = '\0';
		i++;
	}
	return (mem_area);
}
