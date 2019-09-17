/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:18:19 by marvan-d          #+#    #+#             */
/*   Updated: 2019/09/03 09:18:22 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../libft/get_next_line.h"
#include "debug.h"

int	main(void)
{
	//t_map map;
	char *infile;
	char *line;
	int nb_ants;

	nb_ants = 0;
    infile = NULL;
	while (get_next_line(0, &line) > 0 && (line[0] == '#' && line[1] != '#'))
		infile = ft_strjoin(infile, line);
	parse_ants(line, &nb_ants);
	//ft_putnbr(nb_ants);
	prase_rooms(line);
	//prase_links();
	//ft_putstr(file);
}
