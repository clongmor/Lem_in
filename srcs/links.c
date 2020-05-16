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

t_node  *create_node(char *to) {
    t_node *new_link;
    new_link = (t_node *)malloc(sizeof(t_node));
    if (!new_link) {
        return NULL;
    }
    new_link->room = ft_strdup(to);
    new_link->next = NULL;
    return new_link;
}

void    push_link_end(t_room *room, t_node *new_link) {
    t_node *tmp;

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

static int     has_link(t_node *head, char *link)
{
    t_node *curr = head;

    while (curr)
    {
        if (ft_strequ(curr->room, link))
        {
            return (1);
        }
        curr = curr->next;
    }
    return (0);
}

void    add_link(t_env *env, char *src, char *dst) {
    t_room *src_room;
    t_room *dst_room;

    src_room = find_room(env, src);
    dst_room = find_room(env, dst);
    if ((src_room == NULL) || (dst_room == NULL) || (ft_strequ(src, dst) == 1)) {
        ft_putstr("ERROR\n");
        ft_strdel(&src);
        ft_strdel(&dst);
        free_env(env);
        exit(1);
    }
    else {
        if ((has_link(src_room->links, dst) == 0) && (has_link(dst_room->links, src) == 0))
        {
            push_link_end(src_room, create_node(dst));
            push_link_end(dst_room, create_node(src));
        }
        else
        {
            ft_putstr("ERROR\n");
            ft_strdel(&src);
            ft_strdel(&dst);
            free_env(env);
            exit(1);
        }
    }
}