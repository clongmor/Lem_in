#include "../includes/lem.h"

void    free_env_rooms(t_env *env)
{
    if (env->head)
        free_rooms(env->head);
    if (env->start)
        free(env->start);
    if (env->end)
        free(env->end);
    free(env);
}

void    free_and_exit_rooms(char *name, char **room_arr, t_env *env, char *room) {
    if (name != NULL)
        free(name);
    if (room)
        free(room);
    if (room_arr)
    {
        free_array(room_arr);
        free(room_arr);
    }
    free_env_rooms(env);
    ft_putstr("ERROR\n");
    exit(1);
}

void    free_and_exit_links(char **rooms) {
    free_array(rooms);
    free(rooms);
    ft_putstr("ERROR\n");
    exit(1);
} 

void    free_map(t_map *head)
{
    t_map *curr = head;
    t_map *next = NULL;

    while (curr)
    {
        next = curr->next;
        free(curr->line);
        free(curr);
        curr = next;
    }
}

void    free_env(t_env *env)
{
    if (env->start)
        free(env->start);
    if (env->end)
        free(env->end);
    if (env->buff)
        free(env->buff);
    if (env->map)
        free_map(env->map);
    if (env->head)
        free_rooms(env->head);
    free(env);
}
