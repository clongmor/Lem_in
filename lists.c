/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:11:22 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/05 13:56:00 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room	*create_new(char *room_name, int index, int x_val, int y_val)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->room_name = (char *)malloc(sizeof(char) * ft_strlen(room_name) + 1);
	ft_strcpy(new->room_name, room_name);
	new->index = index;
	new->start = FALSE;
	new->end = FALSE;
	new->occupied = FALSE;
	new->coords = malloc(sizeof(t_location));
	(new->coords)->x = x_val;
	(new->coords)->y = y_val;
	return (new);
}

t_room	*create_start(char *room_name, int index, int x_val, int y_val)
{
	t_room	*new;
	
	new = create_new(room_name, index, x_val, y_val);
	new->start = TRUE;
	return (new);
}

t_room	*create_end(char *room_name, int index, int x_val, int y_val)
{
	t_room	*new;
	
	new = create_new(room_name, index, x_val, y_val);
	new->end = TRUE;
	return (new);
}

void	birth_to_parent(t_room **parent, t_room *child)
{
	t_room *cursor;

	cursor = *parent;
	while (cursor->next)
		cursor = (cursor)->next;
	cursor->next = child;
}

t_room	*create_room(char *room_str, int ind, int type)
{
	int	index;
	int	x_val;
	int	y_val;
	char	*room_namestr;
	t_room	*room_name;

	index = 0;
	while (room_str[index] != ' ')
		index++;
	room_namestr = (char*)malloc(sizeof(char) * index + 1);
	ft_strncpy(room_namestr, room_str, index++);
	x_val = ft_atoi(room_str + index);
	while (room_str[index++] != ' ');
	y_val = ft_atoi(room_str + index);
	if (type == 1)
		room_name = create_start(room_namestr, ind, x_val, y_val);
	else if (type == 2)
		room_name = create_end(room_namestr, ind, x_val, y_val);
	else
		room_name = create_new(room_namestr, ind, x_val, y_val);
	free(room_namestr);
	return (room_name);
}
//start = 1
//end = 2
//neither = 0
t_room	**populate_list(t_room **new, char **instr)
{
	t_room	*new_room;
	int		i;
	
	i = 1;
	while (instr[i][1] != '-')
	{
		if (instr[i][0] == '#')
		{
			if (ft_strcmp(instr[i], "##start") == 0)
			{
				i++;
				new_room = create_room(instr[i], 0, 1);
				birth_to_parent(new, new_room);
			}
			else if (ft_strcmp(instr[i], "##end") == 0)
			{
				i++;
				new_room = create_room(instr[i], 0, 2);
				birth_to_parent(new, new_room);
			}
		}
		else
		{
			new_room = create_room(instr[i], 0, 0);
			birth_to_parent(new, new_room);
		}
		i++;
	}		
	return (new);	
}
//assuming all input in correct format.
// **next in struct needs to change