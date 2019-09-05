/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:49:39 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/05 13:50:23 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		main(int argc, char **argv)
{
	int	read;
	char *line;
	t_room	*new;
	
	argv++;
	new = create_new("master", -1, 0, 0); //master node of room_list
	populate_list(&new, argv);
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