/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:26:04 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/24 08:10:40 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in an integer and checks if it corresponds to
** any of the space values in the ascii table. returns
** 1 if true, otherwise 0.
** Uses: no libft functions
*/

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' \
			|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}
