#include "../includes/lem.h"

void    free_env_rooms(t_env *env)
{
    free_rooms(env->head);
    free(env->start);
    free(env->end);
    free(env->buff);
    free(env);
}

void    free_and_exit_rooms(char *name, char **room_arr, t_env *env) {
    if (name != NULL)
        free(name);
    free_array(room_arr);
    free(room_arr);
    free_env_rooms(env);
    ft_putstr("ERROR\n");
    exit(1);
}

void    free_and_exit_links(char **rooms, t_env *env) {
    free_array(rooms);
    free(rooms);
    free_env_rooms(env);
    ft_putstr("ERROR\n");
    exit(1);
} 

void    free_env(t_env *env)
{
    free(env->start);
    free(env->end);
    free(env->buff);
    free(env);
}