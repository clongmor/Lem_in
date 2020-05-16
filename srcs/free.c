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

void    free_env_rooms_exit(t_env *env)
{
    free_rooms(env->head);
    free(env->start);
    free(env->end);
    free(env->buff);
    free(env);
    ft_putendl("ERROR");
    exit(1);
}

void    free_and_exit_rooms(char *name, char **room_arr, t_env *env) {
    if (name != NULL)
        free(name);
    if (room_arr) {
        free_array(room_arr);
        free(room_arr);
    }
    free_env_rooms_exit(env);
}

void    free_and_exit_links(char **rooms, t_env *env) {
    free_array(rooms);
    free(rooms);
    free_env_rooms_exit(env);
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
