/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:48:01 by marvan-d          #+#    #+#             */
/*   Updated: 2019/09/03 10:48:02 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/get_next_line.h"
#include "../../libft/libft.h"
#include "debug.h"

int		str_only_digits(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		 valid_command(char *str)
{
	//More commands can be added
	if (strncmp(str, "start", 5))
		return (1);
	if (strncmp(str, "end", 3))
		return (2);
	return (0);
}

void	parse_ants(char *line, int *nb_ants) //nb ants will be replaced with a pointer to a struct
{
	if (ft_strchr(line, ' ') || !str_only_digits(line))
		error();
	*nb_ants = ft_atoi(line);
}

void	prase_rooms(char *line) //Arguments should be a pointer to a struct
{
	int cmd;

	while (get_next_line(1, &line) > 0)
	{
		if ((line[0] == '#' && line[1] == '#'))
				cmd = valid_command(line + 2);
		else if (line[0] != '#')
		{
			//NOTE: add check if room name has been used
			//Add room logic
			
		}
	}
}

void	error()
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

