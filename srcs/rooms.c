/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rooms_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <clongmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:13:30 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/17 08:45:48 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

t_room  *create_room(char *name, int x, int y) {
    t_room *new_room;

    new_room = (t_room *)malloc(sizeof(t_room));
    if (!new_room) {
        return NULL;
    }
    new_room->x = x;
    new_room->y = y;
    new_room->name = ft_strdup(name);
    new_room->next = NULL;
    new_room->links = NULL;
    return new_room;
}

void    add_room(t_env *env, t_room *room) {
    t_room *tmp;

    tmp = env->head;
    if (!tmp) 
    {
        env->head = room;
    }
    else {
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = room;
    }
}

t_room  *get_room(t_env *env, char *dst) {
    t_room *tmp;

    tmp = env->head;
    while (tmp) {
        if (!ft_strcmp(tmp->name, dst)) {
             return (tmp);
        }
        tmp = tmp->next;
    }
    return NULL;
}