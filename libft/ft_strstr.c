/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:32:35 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 13:44:51 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in two pointers to strings and searches through
** the haystack for the needle. if not found it returns
** NULL, if needle is empty it returns haystack,
** otherwise returns a pointer to the location
** of the first character in needle found in haystack.
** Uses: ft_strlen, ft_strnstr(ft_strncmp)
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		len;

	len = ft_strlen(haystack);
	return (ft_strnstr(haystack, needle, len));
}
