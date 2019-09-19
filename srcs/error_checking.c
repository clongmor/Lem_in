/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:29:50 by marvan-d          #+#    #+#             */
/*   Updated: 2019/09/17 10:29:51 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include #include "../includes/lem.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef struct  s_env
{
    unsigned int    ants : 1;
    unsigned int    links : 1;
    unsigned int    rooms : 1;
    unsigned int    start : 1;
    unsigned int    end : 1;
    char            *room_lst;
    char            *line;
}               t_env;


static  int ft_strnisdigit(char *str, int len)
{
	while (str[len] && len)
	{
		if (str[len] < 48 || str[len] > 57)
			return (0);
		len--;
	}
	return (1);
}

static  int valid_room(char *str)
{
    *str = '\0';
    return (1);
}


static  int ft_strisdigit(char *str)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		str++;
	}
	return (1);
}

static  int validate_coords(char *line)
{
    int space_indx;

    space_indx = ft_strchr(line, ' ') - line;
    if (!line || !space_indx)
        return (0);
    if (ft_strnisdigit(line, space_indx) && ft_strisdigit(line + space_indx + 1))
        return (1);
    return (0);
}

static  void    ft_error(t_env **env)
{
    free((*env)->line);
    //free(env);
    ft_putendl_fd("Error", 2);
    exit(0);
}

static  int get_format(char *str)
{
    if (ft_strchr(str, ' '))
    {
        str += (ft_strchr(str, ' ') - str) + 1;
        if (validate_coords(str))
            return (1);
        return (-1);
    }
    else if (str[0] == '#')
        return (0);
    else if (ft_strchr(str, '-'))
        return (2);
    return (-1);
}



static  void    validate_ants(t_env *env)
{
    while ((get_next_line(0, &(env->line)) < 1) && env->line[0] == '#' && env->line[1] != '#')
    if (!ft_strisdigit(env->line))
        ft_error(&env);
    if (ft_atoi(env->line) < 1)
        ft_error(&env);
    env->ants = 1;
    //free(env->line);
}

static  void     validate_rooms(t_env *env)
{
    int cmd;
    int format;

    //Unique name
    //Format [room name][single space][x_coord][single space][y_coord]
    cmd = 0;
    while (get_next_line(0, &(env->line)) > 0)
    {
        format = get_format(env->line);

        if (format == -1)
            ft_error(&env);
        if (format == 0)
        {
            if (ft_strequ(env->line, "##start"))
                cmd = 1;
            if (ft_strequ(env->line, "##end"))
                cmd = 2;
        }
        else if (cmd == 1 && format == 1)
        {
            env->start = 1;
            cmd = 0;
        }
        else if (cmd == 2 && format == 1)
        {
            env->end = 1;
            cmd = 0;
        }
        else if (format == 2)
            break ;
        else if (valid_room(env->line) == 1)
            ft_error(&env);
    }
    if (env->room_lst != NULL)
        env->rooms = 1;
}

int            read_input()
{
    t_env env;

    validate_ants(&env);
    validate_rooms(&env);

    if (env.rooms && env.ants && env.start && env.end)
        return (1);
    return (0);
    /*
    while (get_next_line(0, &line) > 0)
	{
		//check if not comment
		if (!(line[0] == '#' && line[1] != '#'))
		{
            if (elems_set.ants == 0)
            {
                if (!valid_number(line))
                    return (0);
                elems_set.ants = 1;
            }
            if (elems_set.rooms == 0)
            {
                //Check format

            }
		}
		//store in another double char pointer eachtime and free
		//read all in then operate
	}
    return (elems_set.ants && elems_set.rooms && elems_set.links);
    */
}


int main()
{
    if (read_input() == 1)
        ft_putendl("Valid file");
    else   
        ft_putendl("Invalid file");
    return (0);
}