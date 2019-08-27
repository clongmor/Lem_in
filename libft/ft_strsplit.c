/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:37:28 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/21 10:17:12 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes in a pointer to string and a character to split with.
** It uses ft_wordsplit to count how many words the string will
** split into. it then mallocs that many pointer spaces into a
** double character array. it then uses ft_split. ft_split calls
** ft_wordlenchr counts how long the "word" is between two of the
** specified characters. ft_split then mallocs that much space into
** the relevant slot in the double character array. it then copies
** the string section into the array using strncpy and adds \0. it
** repeats this loop until the supplied string is empty and then
** rteurns the double character array.
** Uses: 3x static functions, ft_strncpy & malloc
*/

#include "libft.h"

static size_t	ft_wordsplit(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || ((i - 1) < 0)))
			count += 1;
		i++;
	}
	return (count);
}

static size_t	ft_wordlenchr(const char *s, size_t index, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i + index] != c && s[i + index] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char		**ft_split(char **str_array, const char *s, char c)
{
	int	i;
	int	j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || ((i - 1) < 0)))
		{
			count = ft_wordlenchr(s, i, c);
			str_array[j] = (char *)malloc(count * sizeof(char) + 1);
			ft_strncpy(str_array[j], (s + i), count);
			str_array[j][count] = '\0';
			j++;
			i = i + count;
		}
		else
			i++;
	}
	str_array[j] = NULL;
	return (str_array);
}

char			**ft_strsplit(const char *s, char c)
{
	int		count;
	char	**str_array;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	count = ft_wordsplit(s, c);
	str_array = (char **)malloc((count + 1) * sizeof(s));
	if (str_array == NULL)
		return (NULL);
	if (count == 0)
	{
		str_array[0] = NULL;
		return (str_array);
	}
	return (ft_split(str_array, s, c));
}
