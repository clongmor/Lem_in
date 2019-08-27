/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:33:06 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 14:39:32 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in 2 strings and compares them character by
** character using memcmp, and returns 1, 0 or -1,
** depending whether s1 > s2, s1 = s2 or s1 < s2.
** Uses: ft_strlen, ft_memcmp
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2) + 1;
	if (s1_len <= s2_len)
		i = ft_memcmp(s1, s2, s1_len);
	else
		i = ft_memcmp(s1, s2, s2_len);
	if (i > 0)
		return (1);
	else if (i == 0)
		return (0);
	else
		return (-1);
}
