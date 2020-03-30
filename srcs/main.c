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
    print_env(anthill);
	//while ((read = get_next_line(0, &line)) == 1)
	//{
		//store in another double char pointer eachtime and free
		//read all in then operate
	//}
	//read from stdinput
	//error checking
	// create lists with coords
	//add room links
	//call algorithim with # of ants
	//free lists
	return (0);
}