/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:49:39 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/28 15:37:54 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef	struct	s_location 
{
	int	x;
	int	y;
}				t_location;

typedef struct s_room
{
	int				index;
	t_bool			start;
	t_bool			end;
	t_bool			occupied;
	char			*room_name;
	t_location		*coords;
	struct s_room	*next;
}				t_room;

int		main(int argc, char **argv)
{
	int	read;
	int	ant_no;
	char *line;

	if (!(line = (char*)malloc(sizeof(char)*3)));
		return (0);
	while ((read = get_next_line(0, &line)) == 1)
	{
		//do i need to use one line at a time or read all in then operate
	}
	//read from stdinput
	//error checking
	// create lists with coords
	//add room links
	//call algorithim with # of ants
	//free lists
	return (0);
}