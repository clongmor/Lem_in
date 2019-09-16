/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <clongmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:22:31 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/16 10:51:54 by clongmor         ###   ########.fr       */
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

typedef struct s_link
{
	t_room			*to;
	t_room			*from;
	struct s_link	*next;
}				t_link;

t_room	*create_new_r(char *room_name, int index, int x_val, int y_val);
t_room	*create_end(char *room_name, int index, int x_val, int y_val);
t_room	*create_start(char *room_name, int index, int x_val, int y_val);
void	birth_to_parent(t_room **parent, t_room *child);
t_room	*create_room(char *room_str, int ind, int type);
t_room	**populate_room_list(t_room **new, char **instr);
t_link	**populate_room_link(t_link **new_links, char **argv, t_room **rooms);
t_link	*create_link(char *link_instr, t_room **rooms);
t_link	*create_masterlink();
void	birth_to_parent_link(t_link **parent, t_link *child);