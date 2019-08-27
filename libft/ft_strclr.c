/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:41:52 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/20 08:07:38 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a string and it clears the memory and zero's
** the memory of the string. Returns nothing.
** Uses: ft_bzero, ft_strlen
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s == NULL)
		return ;
	ft_bzero(s, ft_strlen(s));
}
