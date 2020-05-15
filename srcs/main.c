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

static  void    free_queue(t_queue *head)
{
    t_queue *curr = head;
    t_queue *next = NULL;

    while (curr) {
        next = curr->next;
        free_links(curr->path);
        curr = next;
    }
}

static void    free_env(t_env *env, t_queue *queue)
{
    free_rooms(env->head);
    free(env->start);
    free(env->end);
    free(env->buff);
    free(env);
    free_queue(queue);
    free(queue);
}


int		main()
{
    t_env *anthill;
    
    anthill = create_env();
    parse_ants(anthill);
    read_map_rooms(anthill);
    read_map_links(anthill);
    t_queue *paths = get_paths(anthill);
    if (paths) {
        print_map(anthill);
        ft_putchar('\n');    
        move_ants(anthill, paths);
    }
    else {
        free_env(anthill, paths);
        ft_putendl("ERROR");
        //need to free here
    }
    free_env(anthill, paths);
	return (0);
}