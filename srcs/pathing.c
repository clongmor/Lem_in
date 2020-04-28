#include "../includes/lem.h"

void bfs(t_env *env, char *start, char *dst) {
    // path = find_path
    char **prev;

    prev = explore(env, start);
    char **path = reconstruct_path(start, dst, prev);
}

char **explore(t_env *env, char *start)
{
    // Create queue and add enqueue(start)
    enqueue(start);
    // Create bolean arr of visited rooms of size env
    // visited[start] = true
    // While queue is not empty
        // node = dequeue()
        // links = get_neighbours(node)
        // for every link 
            // if not visited
                // enqueue link
                // visited[link] = true
                // prev[link] = true
    // retrurn prev

}


