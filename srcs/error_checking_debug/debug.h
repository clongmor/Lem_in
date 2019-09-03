/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:00:05 by marvan-d          #+#    #+#             */
/*   Updated: 2019/09/03 10:00:06 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct s_map
{
	char ants_read : 1;
	char rooms_read : 1;
	char links_read : 1;
}				t_map;
*/

void	error(void);
void	parse_ants(char *line, int *nb_ants);
void	prase_rooms(char *line);
