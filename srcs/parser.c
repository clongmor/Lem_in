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
            ft_putstr("Error parsing nb ants line 14");
            exit(1);
        }
        else
        {
            env->nb_ants = ants;
        }
        free(env->buff);
    }
    else
    {
        ft_putstr("Error parsing nb ants line");
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
        if (only_digits(room_arr[1]) && only_digits(room_arr[1]))
        {
            name = ft_strdup(room_arr[0]);
            x = ft_atoi(room_arr[1]);
            y = ft_atoi(room_arr[2]);
            new_room = create_room(name, x, y);
            add_room(env, new_room);
            if (type == 1)
                env->start = name;
            else if (type == 2)
                env->end = name;
        }
        else
        {
            printf("Invalid coordinates");
        }
        
        

    } else {
        printf("Incorrect num spaces");
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
            printf("Could not find rooms\n");
        }
    }
    else
    {
        printf("Incorrect format: %s\n", room);
    }
}

void    read_map_rooms(t_env *env) {
    int room_type;
    
    while (get_next_line(0, &env->buff) > 0) {
        if (ft_strequ(env->buff, "##start")) {
            room_type = 1;
        }
        else if (ft_strequ(env->buff, "##end")) {
            room_type = 2;
        }
        else if (env->buff[0] != '#') {
            if (ft_strchr(env->buff, ' '))
            {
                parse_room(env->buff, room_type, env);
                room_type = 0;
            } 
            else
            {
                return ;
            }
        }
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
            return ;
        }
        free(env->buff);
        if (get_next_line(0, &env->buff) <= 0)
            env->buff = NULL;
    }
}