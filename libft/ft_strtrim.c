/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:48:57 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 09:55:44 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string and uses the static
** functions to check for white spaces before and after
** any other characters in the string. it then allocates
** allocates memory for the string without white spaces
** at the start or end and copies across the contents
** excluding those whites spaces before and after. It
** returns the new copied string.
** Uses: 2x static funtions, ft_strlen && malloc.
*/

#include "libft.h"

static size_t		ft_check_wspacef(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == ' ' \
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

static size_t		ft_check_wspaceb(char *str)
{
	size_t	i;

	if (ft_strlen(str) == 0)
		i = 0;
	else
		i = ft_strlen(str) - 1;
	while (i > 0 && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' \
				|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f'))
		i--;
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char	*ws_str;
	size_t	i;
	size_t	start_index;
	size_t	end_index;

	i = 0;
	if (!s)
		return ((char*)s);
	start_index = ft_check_wspacef((char *)s);
	end_index = ft_check_wspaceb((char *)s);
	if (end_index < start_index)
		return (ft_strnew(0));
	ws_str = (char *)malloc((end_index - start_index + 2) * sizeof(char));
	if (ws_str == NULL)
		return (NULL);
	i = 0;
	while ((i + start_index) <= (end_index))
	{
		ws_str[i] = s[i + start_index];
		i++;
	}
	ws_str[i] = '\0';
	return (ws_str);
}
