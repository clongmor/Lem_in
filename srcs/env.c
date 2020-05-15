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

t_env   *create_env(void) {
    t_env *new_env;

    new_env = (t_env *)malloc(sizeof(t_env));
    if (!new_env) {
        return NULL;
    }
    new_env->head = NULL;
    new_env->size = 0;
    new_env->map = NULL;
    new_env->start = NULL;
    new_env->end = NULL;
    return new_env;
}

void    print_map(t_env *env) {
    t_map *prev;

    while (env->map) {
        prev = env->map;
        env->map = env->map->next;
        ft_putendl(prev->line);
        free(prev->line);
        free(prev);
    }
}

void    push_buffer(t_env *env) {
    t_map *new_map;
    t_map *cursor;

    if (env->buff)
    {
        new_map = (t_map *)malloc(sizeof(t_map));
        new_map->line = ft_strdup(env->buff);
        new_map->next = NULL;
        if (env->map == NULL)
            env->map = new_map;
        else {
            cursor = env->map;

            while (cursor->next)
                cursor = cursor->next;
            cursor->next = new_map;
        }
        free(env->buff);
        env->buff = NULL;
    }
}

void    print_env(t_env *env) {
    t_room *tmp;

    tmp = env->head;
    printf("nb ants: %i\n", env->nb_ants);
    while (tmp) {
        printf("room: %s | links : ", tmp->name);
        t_node *tmp_link = tmp->links;
        while (tmp_link) {
            printf("%s ", tmp_link->room);
            tmp_link = tmp_link->next;
        }
        printf("\n");
        // Print links
        tmp = tmp->next;
    }
    printf("start: %s\nend: %s\n", env->start, env->end);
}

void free_links(t_node *head) {
    t_node *curr = head;
    t_node *next = NULL;

    while (curr) {
        next = curr->next;
        free(curr->room);
        free(curr);
        curr = next;
    }
}

void free_rooms(t_room *head) {
    t_room *curr = head;
    t_room *next = NULL;

    while (curr) {
        next = curr->next;
        free_links(curr->links);
        // free(curr->links);
        // ft_putendl("")
        free(curr->name);
        curr->name = NULL;
        free(curr);
        curr = NULL;
        curr = next;
    }
}