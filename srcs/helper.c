#include "../includes/lem.h"

int only_digits(char *str) {
    int digit_count;

    digit_count = 0;
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