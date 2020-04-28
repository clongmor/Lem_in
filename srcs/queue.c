#include "../includes/lem.h"

void enqueue(t_node **queue, t_node *node) {
    t_node *tmp;

    tmp = *queue;
    if (!tmp) {
        *queue = node;
    }
    else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

t_node *dequeue(t_node **queue) {
    if (*queue) {
        t_node *front;

        front = *queue;
        free(*queue);
        *queue = front->next;
        return front;
    }
    return NULL;
}

void    reverse(t_node **queue) {
    t_node *cursor;
    t_node *tail;

    tail = *queue;
    while (tail->next != NULL) {
        printf(" i ");
        tail = tail->next;
    }

    cursor = dequeue(queue);
    // printf("HEAD: %s || CURSOR: %s\n", tail->room, cursor->room);
    while (cursor != tail) {
        enqueue(queue, cursor);
        cursor = dequeue(queue);
    }
    enqueue(queue, cursor);
}
