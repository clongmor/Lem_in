#include "../includes/lem.h"

int only_digits(char *str) {
    int digit_count;

    digit_count = 0;
    if (ft_memcmp(str, "-", 1) == 0 || ft_memcmp(str, "+", 1) == 0)
        str++;
    while (*str) {
        if (ft_isdigit(*str) == 0) {
            return (0);
        }
        digit_count++;
        str++;
    }
    return ((digit_count > 0));
}

int arr_size(char **arr) {
    int size;

    size = 0;
    while (arr[size]) {
        size++;
    }
    return size;
}

void print_links(t_node *head) {
    while (head != NULL) {
        ft_putstr("L: [");
        ft_putstr(head->room);
        ft_putstr("] ");
        head = head->next;
    }
    ft_putstr("\n");
}

int list_contains(t_node *head, char *dst) {
    while (head) {
        if (head->room == dst)
            return (1);
        head = head->next;
    }
    return (0);
}

void    free_array(char **arr) {
    char *prev;

    while (*arr)
    {
        prev = *arr;
        arr++;
        free(prev);
    }
    arr = NULL;
}
