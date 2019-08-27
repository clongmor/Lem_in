/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:19:28 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 13:22:34 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings, and uses strcpy to copy
** s2 into s1, starting at the \0 at the end of s1. returns
** the destination string.
** Uses: ft_strlen, ft_strcpy(memcpy)
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	n;

	n = ((size_t)ft_strlen(s1));
	ft_strcpy((s1 + n), s2);
	return (s1);
}
