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

#include #include "../includes/lem.h"

typedef struct  s_env
{
    unsigned int    ants : 1;
    unsigned int    links : 1;
    unsigned int    rooms : 1;
    unsigned int    start : 1;
    unsigned int    end : 1;
    char            **rooms;
    char            *line;
}               t_env;

static  void    ft_error(t_env *env)
{
    free(env->line);
    //free(env);
    ft_putendl_fd(2, "Error");
    exit(0);
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

static  void    validate_ants(t_env env)
{
    while ((get_next_line(0, &env->line) < 1) && env->line[0] == '#' && env->line[1] != '#')
    if (!ft_strisdigit(env->line))
        ft_error(&env);
    if (ft_atoi(env->line) < 1)
        ft_error(&env);
    env->ants = 1;
    //free(env->line);
}

static  int     validate_rooms()
{
    //Unique name
    //Format [room name][single space][x_coord][single space][y_coord]
}

void            read_input()
{
    t_env env;

    if (validate_ants(&env) && validate_rooms(&) && validate_links(&env))
        
    else
        exit_and_free(&env);
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