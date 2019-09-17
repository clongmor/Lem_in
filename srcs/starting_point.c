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

int		main(int argc, char **argv)
{
	int	read;
	char *line;
	t_room	*new_rooms;
	t_link	*new_links;
	
	argv++;
	new_rooms = create_new_r("master", -1, 0, 0); //master node of room_list
	new_links = create_masterlink(); //master node of links list
	populate_room_list(&new_rooms, argv);
	populate_room_link(&new_links, argv, &new_rooms);
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