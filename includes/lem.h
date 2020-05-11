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
typedef struct  s_node  t_node;
typedef struct  s_room  t_room;
typedef struct  s_queue t_queue;


struct  s_node {
    char    *room;
    t_node  *next;
};

struct  s_queue {
    t_node *path;
    t_queue  *next;
};

struct  s_room
{
    int             index;
    int             x;
    int             y;
    char            *name;
    t_node          *links;
    t_room          *next;
};

typedef struct  s_env {
    int     nb_ants;
    int     size;
    t_room  *head;
    char    *start;
    char    *end;
    char    *buff;
}               t_env;

t_env   *create_env(void);
t_room  *create_room(char *name, int x, int y, int index);
t_node  *create_node(char *dst);
t_room  *find_room(t_env *env, char *dst);
void    add_link(t_env *env, char *src, char *dst);
void    push_link_end(t_room *room, t_node *new_link);
void    add_room(t_env *env, t_room *room);
void    print_env(t_env *env);
void    delete_env(t_env *env);
void    parse_ants(t_env *env);
int     only_digits(char *str);
void    read_map_rooms(t_env *env);
void    parse_room(char *room, int type, t_env *env);
int     arr_size(char **arr);
void    read_map_links(t_env *env);
void    parse_link(char *room, t_env *env);
t_node  *dequeue(t_queue **queue);
void    enqueue(t_queue **queue, t_node *new_path);
void    print_links(t_node *head);
t_queue *get_paths(t_env *env);
void    print_queue(t_queue **queue);
t_queue *create_queue(t_node *path);
t_node  *appended_path(t_node **path, char *to_append);
char    *last_in_path(t_node *path);
int     room_count(t_node *path, char *room);
void    check_start_end(t_env *env);
#endif