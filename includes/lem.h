/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <clongmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:22:31 by clongmor          #+#    #+#             */
/*   Updated: 2019/09/17 08:34:22 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef int bool;
typedef struct  s_link  t_link;
typedef struct  s_room  t_room;

struct  s_link {
    char    *room;
    t_link  *next;
};

struct  s_room
{
    int             x;
    int             y;
    int             index;
    char            *name;
    t_link          *links;
    t_room          *next;
};

typedef struct  s_env {
    int     nb_ants;
    t_room  *head;
    char    *start;
    char    *end;
}               t_env;

t_env   *create_env(void);
t_room  *create_room(char *name, int x, int y);
t_link  *create_link(char *dst);
t_room  *get_room(t_env *env, char *dst);
void    add_link(t_env *env, char *src, char *dst);
void    push_link_end(t_room *room, t_link *new_link);
void    add_room(t_env *env, t_room *room);
void    print_env(t_env *env);
void    delete_env(t_env *env);
void    parse_ants(t_env *env);
int     str_only_digits(char *str);
void    read_map_rooms(t_env *env);
void    parse_room(char *room, int type, t_env *env);


#endif