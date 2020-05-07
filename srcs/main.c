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
    print_env(anthill);
    t_room *head = anthill->head;
    t_node *sp = find_path(anthill, NULL);
    t_node *sp2 = find_path(anthill, sp);

    ft_putstr("first path: ");
    print_links(sp);
    ft_putstr("second path: ");
    print_links(sp2);
    // char **path = ft_strsplit("a,b,c", ',');

	return (0);
}