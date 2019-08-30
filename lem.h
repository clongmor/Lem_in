/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:22:31 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/30 14:40:23 by clongmor         ###   ########.fr       */
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
	struct s_room	**next;
}				t_room;

t_room	*create_new(char *room_name, int index, int x_val, int y_val);
t_room	*create_end(char *room_name, int index, int x_val, int y_val);
t_room	*create_start(char *room_name, int index, int x_val, int y_val);