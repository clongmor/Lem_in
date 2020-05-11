/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <clongmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:49:39 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/17 08:45:48 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"


int		main()
{
    t_env *anthill;
    
    anthill = create_env();
    parse_ants(anthill);
    read_map_rooms(anthill);
    read_map_links(anthill);
    t_room *head = anthill->head;
    t_queue *paths = get_paths(anthill);
    print_map(anthill);
    ft_putchar('\n');
    move_ants(anthill, paths);

	return (0);
}