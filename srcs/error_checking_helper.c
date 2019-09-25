#include "../includes/lem.h"

void    ft_error(t_env **env, int ln_nb)
{
    ft_strdel(&(*env)->line);
    //free(env);
    ft_putstr_fd("Error at ", 2);
    ft_putendl_fd(ft_itoa(ln_nb), 2);
    exit(0);
}

int room_exists(char *room, t_env *env)
{
	int i;

	i = -1;
	ft_putendl("line 17");
	while (++i < env->nbr_rooms)
	{
		if (ft_strequ(room, env->all_rooms[i]))
			return (1);
	}
	ft_putendl("line 23");
	env->all_rooms = realloc(env->all_rooms, env->nbr_rooms * sizeof(*(env->all_rooms)));
	ft_putendl("line 25");
	ft_strcpy(env->all_rooms[env->nbr_rooms - 1], room);
	ft_putendl("line 27");
	return (0);
}

int ft_strnisdigit(char *str, int len)
{
	while (str[len] && --len)
	{
		if (str[len] < 48 || str[len] > 57)
			return (0);
	}
	return (1);
}

int ft_strisdigit(char *str)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		str++;
	}
	return (1);
}

int     set_cmd(char *line)
{
    if (ft_strequ(line, "##start"))
        return (1);
    if (ft_strequ(line, "##end"))
        return (2);
    return (0);
}