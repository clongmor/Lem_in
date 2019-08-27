/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:40:07 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 14:38:37 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and a length,
** it copmares them character by character, using
** memcmp, comparing at most n characters. returns
** 1, 0, or -1, depending on whether s1 > s2,
** s1 = s2, s1 < s2.
** Uses: ft_strlen, ft_memcmp
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2) + 1;
	if (s1_len <= s2_len)
	{
		if (s1_len < n)
			n = s1_len;
	}
	else if (s2_len < n)
		n = s2_len;
	i = (ft_memcmp(s1, s2, n));
	if (i > 0)
		return (1);
	else if (i == 0)
		return (0);
	else
		return (-1);
}
