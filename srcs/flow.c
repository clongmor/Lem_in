#include "../includes/lem.h"

static t_ant *create_ant(int name, char *room)
{
    t_ant *new_ant;

    new_ant = (t_ant *)malloc(sizeof(t_ant));
    if (!new_ant)
        return NULL;

    new_ant->name = name;
    new_ant->room = ft_strdup(room);
    new_ant->next = NULL;
    return new_ant;
}

void push_ant(t_ant **head, t_ant *new_ant)
{
    t_ant *curr = *head;

    if (!(*head))
    {
        *head = new_ant;
    }
    else
    {
        while (curr->next)
            curr = curr->next;
        curr->next = new_ant;
    }
}

static t_ant *genererate_ants(int nb_ants, char *start_room)
{
    int curr_ant = 1;
    t_ant *head = NULL;
    t_ant *tmp = NULL;

    while (curr_ant <= nb_ants)
    {
        tmp = create_ant(curr_ant, start_room);
        push_ant(&head, tmp);
        curr_ant++;
    }
    return head;
}

static void delete_ant(t_ant **head, int to_del)
{
    t_ant *curr = *head;
    t_ant *prev = curr;

    if (*head && to_del)
    {
        if ((*head)->name == to_del)
        {
            t_ant *next = (*head)->next;
            free((*head)->room);
            free(*head);
            *head = next;
        }
        else
        {
            while (curr->next)
            {
                if (curr->name == to_del)
                {
                    free(curr->room);
                    free(curr);
                    t_ant *next = curr->next;
                    prev->next = next;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

static int room_available(char *room, t_ant *ants)
{
    t_ant *curr_ant = ants;

    if (!room)
        return (0);

    while (curr_ant)
    {
        if (ft_strequ(curr_ant->room, room))
        {
            return (0);
        }
        curr_ant = curr_ant->next;
    }
    return (1);
}

static t_node *next_available(t_ant *ant, t_queue *paths, t_ant *ants)
{
    t_queue *queued_path = paths;
    t_node *path = NULL;

    while (queued_path)
    {
        path = queued_path->path;

        while (path)
        {
            if (ft_strequ(path->room, ant->room) && (room_available(path->next->room, ants) == 1))
            {
                return path->next;
            }
            path = path->next;
        }
        queued_path = queued_path->next;
    }
    return NULL;
}

static void print_move(int ant, char *room, int moved)
{
    if (moved != 0)
        ft_putchar(' ');
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(room);
}

void move_ants(t_env *env, t_queue *paths)
{
    t_ant *ants = genererate_ants(env->nb_ants, env->start);
    t_node *next = NULL;
    t_ant *cursor = NULL;
    // next = next_available(ants, paths, ants);

    while (ants)
    {
        cursor = ants;
        int moved_ants = 0;

        while (cursor)
        {
            next = next_available(cursor, paths, ants);
            if (next != NULL)
            {
                if (ft_strequ(next->room, env->end))
                {
                    print_move(cursor->name, next->room, moved_ants);
                    delete_ant(&ants, cursor->name);
                    moved_ants = 1;
                }
                else
                {
                    print_move(cursor->name, next->room, moved_ants);
                    ft_strdel(&(cursor->room));
                    cursor->room = ft_strdup(next->room);
                    moved_ants = 1;
                }
            }
            cursor = cursor->next;
        }
        ft_putchar('\n');
    }
}