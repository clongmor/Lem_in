/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <clongmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:11:22 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/17 08:45:48 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

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