#include "../includes/lem.h"

void    parse_ants(t_env *env) {
    char    *buff;
    int     ants;
    int     b_read;

    b_read = get_next_line(0, &buff);
    // printf("%i\n", b_read);
    // ft_putendl(buff);
    if (buff && b_read >= 1)
    {
        ants = ft_atoi(buff);
        if (ants < 1 || (str_only_digits(buff) == 0))
        {
            ft_putstr("Error parsing nb ants line 14");
            exit(1);
        }
        else
        {
            env->nb_ants = ants;
        }
    }
    else
    {
        ft_putstr("Error parsing nb ants line");
        exit(1);
    }
}

void    parse_room(char *room, int type, t_env *env) {
    // convert and add room
    char *name;
    t_room *new_room;
    int x;
    int y;
    int delim;

    delim = ft_strchr(room, ' ') - room;
    name = ft_strndup(room, delim);
    room += delim;
    new_room = create_room(name, 0, 0);
    add_room(env, new_room);
    if (type == 1)
    {
        env->start = name;
    }
    else if (type == 2)
    {
        env->end = name;
    }
}

// void    parse_link(char *room) {
//     // convert and add room
// }

void    read_map_rooms(t_env *env) {
    char *buff;
    int room_type;
    
    while (get_next_line(0, &buff) > 0) {
        if (ft_strequ(buff, "##start")) {
            room_type = 1;
        }
        else if (ft_strequ(buff, "##end")) {
            room_type = 2;
        }
        else if (buff[0] != '#') {
            if (ft_strchr(buff, ' '))
            {
                parse_room(buff, room_type, env);
                room_type = 0;
            } 
            else
                return ;
        }

    }
}

// void    read_map_links(t_env *env) {

// }