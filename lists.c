/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <clongmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:11:22 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/16 12:06:22 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room	*create_new_r(char *room_name, int index, int x_val, int y_val)
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
	
	new = create_new_r(room_name, index, x_val, y_val);
	new->start = TRUE;
	return (new);
}

t_room	*create_end(char *room_name, int index, int x_val, int y_val)
{
	t_room	*new;
	
	new = create_new_r(room_name, index, x_val, y_val);
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
		room_name = create_new_r(room_namestr, ind, x_val, y_val);
	free(room_namestr);
	return (room_name);
}
//start = 1
//end = 2
//neither = 0
t_room	**populate_room_list(t_room **new, char **instr)
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
			if (instr[i][1] == '-')
				break ;
			new_room = create_room(instr[i], 0, 0);
			birth_to_parent(new, new_room);
		}
		i++;
	}		
	return (new);	
}

void	birth_to_parent_link(t_link **parent, t_link *child)
{
	t_link *cursor;

	cursor = *parent;
	while (cursor->next)
		cursor = (cursor)->next;
	cursor->next = child;
}

t_link	*create_masterlink()
{
	t_link	*new_master;

	if (!(new_master = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	new_master->to = NULL;
	new_master->from = NULL;
	new_master->next = NULL;
	return (new_master);
}

t_link	*create_link(char *link_instr, t_room **rooms)
{
	t_link	*link;
	int		i;
	char	*room_name2;
	t_room	*temp;

	temp = (*rooms);
	i = 0;
	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	while (link_instr[i] != '-')
		i++;
	room_name2 = ft_strndup(link_instr, i);
	while (temp != NULL)
	{
		if (ft_strcmp(temp->room_name, room_name2) == 0)
		{
			link->from = temp;
			break ;
		}
		else
			temp = temp->next;
	}
	free(room_name2);
	i++;
	room_name2 = ft_strdup(link_instr + i);
	temp = (*rooms);
	while (temp != NULL)
	{
		if (ft_strcmp(temp->room_name, room_name2) == 0)
		{
			link->to = temp;
			break ;
		}
		else
			temp = temp->next;
	}
	free(room_name2);
	room_name2 = NULL;
	link->next = NULL;
	return (link);
}

t_link	**populate_room_link(t_link **new_links, char **argv, t_room **rooms)
{
	t_link	*new_link;
	int		i;

	i = 0;
	while (argv[i][1] != '-')
		i++;
	while (argv[i])
	{
		if (argv[i][0] == '#')
		{
			i++;
			continue ;
		}
		else
		{
			new_link = create_link(argv[i], rooms);
			birth_to_parent_link(new_links, new_link);
			i++;
		}
	}
	return (new_links);
}
//assuming all input in correct format.
// **next in struct needs to change