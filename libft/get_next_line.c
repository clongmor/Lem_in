/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:42:27 by clongmor          #+#    #+#             */
/*   Updated: 2019/07/04 14:03:05 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** a function to read in input from a file descriptor until
** it finds a \n or end of file which is stipulated by \0
** we add. it then stores the line until -not including
** - the newline in the supplied pointer variable. it
** returns -1, 0, or 1, based on whether it found an error,
** finished reading or found a newline and stored it
*/

#include "get_next_line.h"

int		store_line(char **str, char **line, const int fd, int read_no)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + (len + 1));
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (read_no == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strsub(str[fd], 0, ft_strlen(str[fd]));
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[255];
	char			buff[BUFF_SIZE + 1];
	int				read_no;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_no = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		buff[read_no] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (read_no < 0)
		return (-1);
	else if (read_no == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	else
		return (store_line(str, line, fd, read_no));
}
