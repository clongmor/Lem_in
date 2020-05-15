#include "../includes/lem.h"

static int index_of(t_env *env, char *dst)
{
    t_room *room = find_room(env, dst);

    int index = -1;

    if (room)
        index = room->index;
    return index;
}

t_queue *get_paths(t_env *env)
{
    t_room *room = NULL;
    t_node *neighbours = NULL;
    t_queue *paths = NULL;
    t_queue *queue = NULL;
    char *last;
    int size = env->size;
    int visited[size];
    int i = 0;

    while (i < size)
    {
        visited[i] = 0;
        i++;
    }

    t_node *start_node = create_node(env->start);
    enqueue(&queue, start_node);
    free_links(start_node);

    while (queue)
    {
        t_node *curr_path = dequeue(&queue);
        last = last_in_path(curr_path);
        int index = index_of(env, last);

        if (visited[index] == 0)
        {
            room = find_room(env, last);
            neighbours = room->links;
            while (neighbours != NULL)
            {
                t_node *new = appended_path(&curr_path, neighbours->room);
                enqueue(&queue, new);
                if (ft_strequ(neighbours->room, env->end)  && room_count(new, env->end) == 1) {
                    enqueue(&paths, new);
                }
                free_links(new);
                neighbours = neighbours->next;
            }
            visited[index] = 1;
        }
        free_links(curr_path);
    }
    return paths;
}