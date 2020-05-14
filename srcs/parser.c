#include "../includes/lem.h"

void    parse_ants(t_env *env) {
    int     ants;
    int     b_read;

    b_read = get_next_line(0, &env->buff);
    if (env->buff && b_read >= 1)
    {
        ants = ft_atoi(env->buff);
        if (ants < 1 || (only_digits(env->buff) == 0))
        {
            ft_putstr("ERROR\n");
            //need to free here
            exit(1);
        }
        else
        {
            env->nb_ants = ants;
            ft_putendl(env->buff);
        }
        // push_buffer(env);
        free(env->buff);
    }
    else
    {
        ft_putstr("ERROR\n");
        //need to free here
        exit(1);
    }
}

void    parse_room(char *room, int type, t_env *env) {
    // convert and add room
    char **room_arr;
    t_room *new_room;
    int x;
    int y;

    room_arr = ft_strsplit(room, ' ');

    if (arr_size(room_arr) == 3) 
    {
        if (only_digits(room_arr[1]) && only_digits(room_arr[2]))
        {
            char *name = ft_strdup(room_arr[0]);
            x = ft_atoi(room_arr[1]);
            y = ft_atoi(room_arr[2]);
            new_room = create_room(name, x, y, env->size);
            env->size++;
            add_room(env, new_room);
            if (type == 1) {
                if (env->start == NULL) {
                    env->start = ft_strdup(name);
                } else {
                    free(name);
                    free_array(room_arr);
                    free(room_arr);
                    ft_putstr("ERROR\n");
                    exit(1);
                }
            }
            else if (type == 2) {
                if (env->end == NULL) {
                    env->end = ft_strdup(name);
                } else {
                    free(name);
                    free_array(room_arr);
                    free(room_arr);
                    ft_putstr("ERROR\n");
                    exit(1);
                }
            }
            free(name);
        }
        else
        {
            free_array(room_arr);
            free(room_arr);
            ft_putstr("ERROR\n");
            exit(1);
        }
        free_array(room_arr);
        free(room_arr);
    } 
    else {
        free_array(room_arr);
        free(room_arr);
        ft_putstr("ERROR\n");
        exit(1);
    }
}

void    parse_link(char *room, t_env *env) {
    char** rooms;

    rooms = NULL;
    rooms = ft_strsplit(room, '-');
    if (arr_size(rooms) == 2)
    {
        if (find_room(env, rooms[0]) && find_room(env, rooms[1]))
        {
            add_link(env, rooms[0], rooms[1]);
        }
        else
        {
            free(rooms);
            ft_putstr("ERROR\n");
            exit(1);
        }
        free_array(rooms);
        free(rooms);
        rooms = NULL;
    }
    else
    {
        free_array(rooms);
        free(rooms);
        ft_putstr("ERROR\n");
        exit(1);
    }
}

void    read_map_rooms(t_env *env) {
    int room_type;
    int start;
    int end;

    start = 0;
    end = 0;
    while (get_next_line(0, &env->buff) > 0) {
        if (ft_strequ(env->buff, "##start")) {
            room_type = 1;
            start = 1;
            ft_putendl(env->buff);
        }
        else if (ft_strequ(env->buff, "##end")) {
            room_type = 2;
            end = 1;
            ft_putendl(env->buff);
        }
        else if (env->buff[0] != '#') {
            if (ft_strchr(env->buff, ' '))
            {
                if (env->buff[0] == 'L') {
                    ft_putendl("ERROR\n");
                    //need to free buffer here
                    exit(1);
                }
                parse_room(env->buff, room_type, env);
                ft_putendl(env->buff);
                room_type = 0;
            } 
            else
            {
                if (start != 1 || end != 1) {
                    ft_putstr("ERROR\n");
                    //need to free here
                    exit(1);
                }
                if (!env->start || !env->end) {
                    ft_putstr("ERROR\n");
                    //need to free here
                    exit(1);
                }
                return ;
            }
        }
        // push_buffer(env);
        free(env->buff);
    }
}

void    read_map_links(t_env *env) {
    while (env->buff)
    {
        if (env->buff[0] != '#' && ft_strchr(env->buff, '-')) {
            parse_link(env->buff, env);
            ft_putendl(env->buff);
        }
        else if (env->buff[0] != '#')
        {
            ft_putstr("ERROR\n");
            exit(1);
        }
        free(env->buff);
        // push_buffer(env);
        if (get_next_line(0, &env->buff) <= 0)
            env->buff = NULL;
    }
}