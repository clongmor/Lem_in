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

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../includes/lem.h"

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
    while ((get_next_line(0, &(env->line)) > 0) && (env->line[0] == '#'))
        free(env->line);
    if (!ft_strisdigit(env->line))
        ft_error(&env, 109);
    if (ft_atoi(env->line) < 1)
        ft_error(&env, 111);
    env->ants = 1;
    ft_strdel(&env->line);
}

static  void     validate_rooms(t_env *env)
{
    int cmd;
    int format;

    cmd = 0;
    while (get_next_line(0, &(env->line)) > 0)
    {
        format = get_format(env->line);
        if (format == -1)
        {
            ft_putendl(env->line);
            ft_error(&env, 84);
        }
        if (format == 0)
            cmd = set_cmd(env->line);
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
        else if (room_exists(env->line, env))
        {
            ft_error(&env, 150);
        }
        ft_strdel(&env->line);
    }
    env->rooms = 1;
}


static  void    validate_links(t_env *env)
{
    int format;
    int links_count;
    int tmp;

    links_count = 0;
    while (get_next_line(0, &(env->line)) > 0)
    {
        format = get_format(env->line);
        if (format == 1 || format == -1 || (format == 0 && set_cmd(env->line)))
            ft_error(&env, 115);
        if (format == 2)
        {
            tmp = ft_strchr(env->line, '-') - env->line;
            if (!room_exists(env->line, env) && !room_exists(env->line + tmp + 1, env))
                links_count++;
            else
                ft_error(&env, 126);
        }
    }
    env->links = (links_count > 0) ? 1 : 0;
}

int            read_input()
{
    t_env env;

	env.nbr_rooms = 0;
	//env.all_rooms[0] = NULL;

    validate_ants(&env);
    validate_rooms(&env);
    validate_links(&env);

    if (env.ants)
        ft_putendl("Valid ants");
    if (env.rooms)
        ft_putendl("Valid rooms");
    if (env.links)
        ft_putendl("Valid links");
    if (env.start)
        ft_putendl("Start set");
    if (env.end)
        ft_putendl("End set");
    return (0);
}

int main()
{
    read_input();
}