#include "../includes/lem.h"

void    parse_ants(t_env *env) {
    int     ants;
    int     b_read;

    b_read = get_next_line(0, &env->buff);
    // printf("%i\n", b_read);
    // ft_putendl(buff);
    if (env->buff && b_read >= 1)
    {
        ants = ft_atoi(env->buff);
        if (ants < 1 || (only_digits(env->buff) == 0))
        {
            ft_putstr("ERROR1\n");
            exit(1);
        }
        else
        {
            env->nb_ants = ants;
        }
        // push_buffer(env);
        free(env->buff);
    }
    else
    {
        ft_putstr("ERROR2\n");
        exit(1);
    }
}

void    parse_room(char *room, int type, t_env *env) {
    // convert and add room
    char **room_arr;
    t_room *new_room;
    char *name;
    int x;
    int y;

    room_arr = ft_strsplit(room, ' ');

    if (arr_size(room_arr) == 3) 
    {
        if (only_digits(room_arr[1]) && only_digits(room_arr[2]))
        //pretty sure this is meant to check 1 and 2 or room_arr, typo potentially
        {
            name = ft_strdup(room_arr[0]);
            x = ft_atoi(room_arr[1]);
            y = ft_atoi(room_arr[2]);
            new_room = create_room(name, x, y, env->size);
            env->size++;
            add_room(env, new_room);
            if (type == 1)
                env->start = name;
            else if (type == 2)
                env->end = name;
        }
        else
        {
            ft_putstr("ERROR3\n");
            exit(1);
        }
        
    } 
    else {
        ft_putstr("ERROR4\n");
        exit(1);
    }
}

void    parse_link(char *room, t_env *env) {
    char** rooms;

    // char *tmp = ft_strdup(room);
    rooms = ft_strsplit(room, '-');
    // printf("Room after: %s\n", room);
    if (arr_size(rooms) == 2)
    {
        if (find_room(env, rooms[0]) && find_room(env, rooms[1]))
        {
            add_link(env, rooms[0], rooms[1]);
        }
        else
        {
            ft_putstr("ERROR5\n");
            exit(1);
        }
    }
    else
    {
        ft_putstr("ERROR6\n");
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
        }
        else if (ft_strequ(env->buff, "##end")) {
            room_type = 2;
            end = 1;
        }
        else if (env->buff[0] != '#') {
            if (ft_strchr(env->buff, ' '))
            {
                if (env->buff[0] == 'L') {
                    ft_putendl("ERROR7");
                    exit(1);
                }
                parse_room(env->buff, room_type, env);
                room_type = 0;
            } 
            else
            {
                if (start != 1 || end != 1) {
                    ft_putstr("ERROR8\n");
                    exit(1);
                }
                if (!env->start || !env->end) {
                    ft_putstr("ERROR9\n");
                    exit(1);
                }
            }
        }
        // push_buffer(env);
        free(env->buff);
    }
}

void    read_map_links(t_env *env) {
    while (env->buff)
    {
        if (env->buff[0] != '#' && ft_strchr(env->buff, '-'))
            parse_link(env->buff, env);
        else if (env->buff[0] != '#')
        {
            ft_putstr("ERROR10\n");
            exit(1);
        }
        free(env->buff);
        // push_buffer(env);
        if (get_next_line(0, &env->buff) <= 0)
            env->buff = NULL;
    }
}