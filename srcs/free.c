void    free_and_exit_rooms(char *name, char **room_arr) {
    if (name != NULL)
        free(name);
    free_array(room_arr);
    free(room_arr);
    ft_putstr("ERROR\n");
    exit(1);
}

void    free_and_exit_links(char **rooms) {
    free_array(rooms);
    free(rooms);
    ft_putstr("ERROR\n");
    exit(1);
}