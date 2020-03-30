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

t_link  *create_link(char *to) {
    t_link *new_link;
    new_link = (t_link *)malloc(sizeof(t_link));
    if (!new_link) {
        return NULL;
    }
    new_link->room = ft_strdup(to);
    new_link->next = NULL;
    return new_link;
}

void    push_link_end(t_room *room, t_link *new_link) {
    t_link *tmp;

    tmp = room->links;
    if (!tmp) {
        room->links = new_link;
    }
    else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_link;
    }
}

void    add_link(t_env *env, char *src, char *dst) {
    t_room *src_room;
    t_room *dst_room;
    t_link *tmp;

    src_room = get_room(env, src);
    dst_room = get_room(env, dst);
    if ((src_room == NULL) || (dst_room == NULL)) {
        printf("Could not find rooms to link\n");
    }
    else {
        push_link_end(src_room, create_link(dst));
        push_link_end(dst_room, create_link(src));
    }
}