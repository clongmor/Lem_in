#include "libft.h"
#include "get_next_line.h"

int     main()
{
    int b_read;
    char    **line;

    line = malloc(200);
    *line = malloc(50);
    ft_putstr("made line\n");
    b_read = get_next_line(0, line);
    ft_putstr("finished read");
    while (*line) {
        free(*line);
        line++;
    }
    free(line);
    return (0);
}