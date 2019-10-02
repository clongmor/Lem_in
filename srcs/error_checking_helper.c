#include "../includes/lem.h"

/*
char **ft_realloc(char **src, size_t size)
{
	if (!src)
		return (NULL);
	
}
*/

void    ft_error(t_env **env, int ln_nb)
{
    ft_strdel(&(*env)->line);
    //free(env);
    ft_putstr_fd("Error at ", 2);
    ft_putendl_fd(ft_itoa(ln_nb), 2);
    exit(0);
}

int new_room(char *room, t_env *env, int type)
{
	int i;
	int len;

	//ft_putendl(room);

	char *tmp;

	i = -1;
	len = 0;
	if (type == 1)
		len = ft_strchr(room, ' ') - room;
	else if (type == 2)
		len = ft_strchr(room, '-') - room;
	else
		ft_error(&env, 32);
	
	while (++i < env->nbr_rooms)
	{
		/*
		ft_putstr("line \"");
		ft_putstr(room);
		ft_putstr("\" has room \"");
		ft_putstr(env->all_rooms[i]);
		ft_putstr("\"\n");
		if (ft_strequ(room, env->all_rooms[i]))
			return (1);
		*/
	}
	env->all_rooms = realloc(env->all_rooms, (env->nbr_rooms + 1) * sizeof(*env->all_rooms));
	env->nbr_rooms++;
	if (!(env->all_rooms))
		ft_error(&env, 33);
	tmp = ft_strndup(room, len);
	/*
	ft_putstr("Room for :");
	ft_putstr(room);
	ft_putstr(" is : ");
	ft_putendl(tmp);
	*/
	//ft_putendl(tmp);
	//ft_putendl("line 25");
	env->all_rooms[env->nbr_rooms - 1] = ft_strndup(room, len);
	env->all_rooms[env->nbr_rooms] = NULL;
	//ft_putendl(env->all_rooms[env->nbr_rooms - 1]);
	//ft_putendl(env->all_rooms[env->nbr_rooms - 1]);
	//ft_strcpy(env->all_rooms[env->nbr_rooms - 1], room);
	//ft_putendl("line 27");
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