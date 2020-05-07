#include "../includes/lem.h"

static int index_of(t_env *env, char *dst) {
    t_room *room = find_room(env, dst);
    int index = -1;

    if (room)
        index = room->index;
    return index;
}

t_node *find_path(t_env *env, t_node *used_paths) {
    t_room *room = NULL;
    t_node *neighbours = NULL;
    t_node *path = NULL;
    t_queue *queue = NULL;
    t_node *new = NULL;
    char *last = NULL;
    int size = env->size;
    int visited[size];
    int i = 0;

    while (i < size) {
        visited[i] = 0;
        i++;
    }

    enqueue(&queue, create_node(env->start));
    while (queue) {
        path = dequeue(&queue);
        last = last_in_path(path);
        int index = index_of(env, last);

        if (visited[index] == 0) {
            room = find_room(env, last);
            neighbours = room->links;
            while (neighbours != NULL) {
                if (visited[index_of(env, neighbours->room)] == 0)
                {
                    if (ft_strequ(neighbours->room, env->end) || ft_strequ(neighbours->room, env->end)) {
                        new = NULL;
                        new = appended_path(&path, neighbours->room);
                        enqueue(&queue, new);
                    }
                    else if (!contains_room(used_paths, neighbours->room)) {
                        new = NULL;
                        new = appended_path(&path, neighbours->room);
                        enqueue(&queue, new);
                    }

                    if (ft_strequ(neighbours->room, env->end))
                        return new;
                }
                
                neighbours = neighbours->next;
            }
            visited[index] = 1;
            path = NULL;
            neighbours = NULL;
        }
    }
    ft_putendl("could not find path");
    return NULL;
}


