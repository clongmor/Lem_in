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
    return new_env;
}

void    print_map(t_env *env) {
    t_map *prev;

    while (env->map) {
        prev = env->map;
        env->map = env->map->next;
        ft_putendl(prev->line);
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
    printf("nb atns: %i\n", env->nb_ants);
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
    printf("start: %s\nend: %s", env->start, env->end);
}

void    delete_env(t_env *env) {
    // Free everything in env
    if (env != NULL) {
        t_room *tmp_room;

        while (env->head != NULL) {
            t_node *tmp_link;
            
            tmp_room = env->head;
            env->head = env->head->next;
            while (tmp_room->links != NULL) {
                tmp_link = tmp_room->links;
                tmp_room->links = tmp_room->links->next;
                free(tmp_link);
            }
            free(tmp_room);
        }
    }
}