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
    return new_env;
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