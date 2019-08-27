/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:47:50 by clongmor          #+#    #+#             */
/*   Updated: 2019/06/19 14:52:01 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes in a pointer to string, moves past
** all the white space, checks for - or +,
** and then while the characters are digits,
** it converts them to integers and adds them
** to the result. it returns the result (int).
** Uses: ft_isdigit
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int		res;
	long int		i;
	int				neg;

	neg = 1;
	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == ' ' \
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		res *= 10;
		res = res + str[i] - '0';
		i++;
	}
	res *= neg;
	return (res);
}
