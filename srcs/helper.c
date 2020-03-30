#include "../includes/lem.h"

int str_only_digits(char *str) {
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