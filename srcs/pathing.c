#include "../includes/lem.h"

static void print_prev(char **prev, int size) {
    printf("PREF|\n");
    int i = 0;

    while (i < size) {
        printf(": %s\n", prev[i]);
        i++;
    }
    printf("PREF|\n");
}

static void print_path(t_node *head) {
    printf("PATH|\n");
    while (head != NULL) {
        printf(": %s | ", head->room);
        head = head->next;
    }
    printf("PATH|\n");
}

void bfs(t_env *env, char *start, char *dst) {
    // path = find_path
    // char **prev;

    char **prev = get_path(env, start);
    // t_node *path = reconstruct_path(env, start, dst, prev);

    print_prev(prev, env->size);
    // print_path(path);

}

t_node *reconstruct_path(t_env *env, char *start, char *end, char **prev) {
    int index;
    t_node *path;

    path = NULL;
    index = get_index(env, end);
    while (index > 0 && prev[index] != NULL) {
        enqueue(&path, create_node(prev[index]));
        index--;
        printf("I: %i prev%s\n", index, prev[index]);
    }

    // reverse(&path);
    if (path->room == start) {
        return path;
    } else {
        printf("couldn't find path | start %s\n", path->room);
        return NULL;
    }
}

char  **get_path(t_env *env, char *start)
{
    // Create queue and add enqueue(start)
    t_node *queue = create_node(start);
    int size = env->size;
    int visited[size];
    char **prev = (char **)malloc(sizeof(char *) * size);
    t_node *tmp;
    t_room *room;
    t_node *neighbours;
    t_room *neighbour;

    while (size != 0) {
        visited[size - 1] = 0;
        prev[size] = NULL;
        size--;
    }

    visited[(find_room(env, start)->index)] = 1;
    // prev[0] = ft_strdup(start);

    while(queue != NULL) {
        tmp = dequeue(&queue);
        room = find_room(env, tmp->room);
        neighbours = room->links;

        while (neighbours != NULL) {
            neighbour = find_room(env, neighbours->room);
            if (visited[neighbour->index] == 0) {
                enqueue(&queue, create_node(neighbour->name));
                visited[neighbour->index] = 1;
                prev[neighbour->index] = ft_strdup(room->name);
            }

            neighbours = neighbours->next;
        }    
    }
    return prev;
}

int     get_index(t_env *env,char *room_name) {
    t_room *room = find_room(env, room_name);
    return (room->index);
}
