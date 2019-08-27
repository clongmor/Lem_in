/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:49:39 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/27 16:51:22 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
