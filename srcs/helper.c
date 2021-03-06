#include "../includes/lem.h"

int only_digits(char *str)
{
    int digit_count;

    digit_count = 0;
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (ft_isdigit(*str) == 0)
        {
            return (0);
        }
        digit_count++;
        str++;
    }
    return ((digit_count > 0));
}

int arr_size(char **arr)
{
    int size;

    size = 0;
    while (arr[size])
    {
        size++;
    }
    return size;
}

int list_contains(t_node *head, char *dst)
{
    while (head)
    {
        if (head->room == dst)
            return (1);
        head = head->next;
    }
    return (0);
}

void free_array(char **arr)
{
    char *prev;

    while (*arr)
    {
        prev = *arr;
        arr++;
        free(prev);
    }
    arr = NULL;
}

int int_overflow(char *str)
{
    int ret;

    ret = 0;
    if (ft_strequ(str, "-2147483648"))
        return (0);
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        ret = ret * 10 + (int)(*str - '0');
        if (ret < 0)
            return (1);
        str++;
    }
    return (0);
}