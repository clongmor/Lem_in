#include "../includes/lem.h"

static t_node *clone_path(t_node *head)
{
    t_node *curr = head;
    t_node *new_path = NULL;
    t_node *tail = NULL;

    while (curr)
    {
        if (new_path == NULL)
        {
            new_path = create_node(curr->room);
            tail = new_path;
        }
        else
        {
            tail->next = create_node(curr->room);
            tail = tail->next;
        }
        curr = curr->next;
    }
    return (new_path);
}

t_queue *create_queue(t_node *path)
{
    t_queue *new_queue = NULL;

    new_queue = (t_queue *)malloc(sizeof(t_queue));

    if (!new_queue)
        return NULL;
    new_queue->path = clone_path(path);
    new_queue->next = NULL;
    return new_queue;
}

t_node *appended_path(t_node **path, char *to_append)
{
    t_node *new = NULL;
    t_node *p = NULL;
    t_node *prev = NULL;
    t_node *cursor = *path;


    if (!cursor)
        return NULL;

    while (cursor != NULL)
    {
        p = create_node(cursor->room);
        if (!new)
        {
            new = p;
        }
        else
        {
            prev->next = p;
        }
        prev = p;
        cursor = cursor->next;
    }
    prev->next = create_node(to_append);
    return new;
}

char *last_in_path(t_node *path)
{
    t_node *curr;

    curr = path;
    if (curr == NULL)
        return NULL;

    if (curr->next == NULL) {
        return curr->room;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr->room;
}

void enqueue(t_queue **queue, t_node *new_path)
{
    t_queue *cursor;

    cursor = *queue;
    if (!cursor)
    {
        *queue = create_queue(new_path);
    }
    else
    {
        while (cursor->next != NULL)
            cursor = cursor->next;
        cursor->next = create_queue(new_path);
    }
}

t_node *dequeue(t_queue **queue)
{
    t_queue *next = NULL;
    t_node *ret = NULL;

    if (*queue)
    {
        next = (*queue)->next;
        ret = (*queue)->path;
        free(*queue);
        *queue = next;
        return ret;
    }
    return NULL;
}

int room_count(t_node *path, char *room)
{
    t_node *curr = path;
    int count = 0;

    if (curr && room)
    {
        while (curr)
        {
            if (ft_strequ(curr->room, room))
                count++;
            curr = curr->next;
        }
    }
    return (count);
}
