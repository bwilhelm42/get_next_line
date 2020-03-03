/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:28:04 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/02 22:00:24 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*file[FD_MAX];
	long		ret;
	long		index;

	if (BUFF_SIZE >= INT_MAX || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (!file[fd])
	{
		file[fd] = (char*)malloc(BUFF_SIZE + 1);
		file[fd][BUFF_SIZE] = '\0';
		file[fd][0] = '\0';
	}
	else if (find_nl(&file[fd], line))
		return (1);
	index = ft_strlen(file[fd]);
	while ((ret = read(fd, &file[fd][index], BUFF_SIZE)) > 0)
	{
		file[fd][ret + index] = '\0';
		if (find_nl(&file[fd], line))
			return (1);
		else if (ret < BUFF_SIZE)
			return (handle_eof(&file[fd], line));
		index += BUFF_SIZE;
	}
	return ((ret == -1) ? -1 : (handle_eof(&file[fd], line)));
}

int		find_nl(char **file, char **line)
{
	long i;
	long len;
	char *temp;

	i = 0;
	if ((i = ft_strclen(*file, '\n')) || **file == '\n')
	{
		*line = (char*)malloc(i + 1);
		(*line)[i] = '\0';
		ft_strncpy(*line, *file, i);
		temp = (char*)malloc(ft_strlen(&(*file)[i]));
		ft_strcpy(temp, &(*file)[i + 1]);
		free(*file);
		*file = temp;
		return (1);
	}
	len = ft_strlen(*file);
	temp = (char*)malloc(len + BUFF_SIZE + 1);
	temp[len + BUFF_SIZE] = '\0';
	ft_strcpy(temp, *file);
	free(*file);
	*file = temp;
	return (0);
}

int		handle_eof(char **file, char **line)
{
	long len;

	len = ft_strlen(*file);
	*line = (char*)malloc(len + 1);
	ft_strcpy(*line, *file);
	(*line)[len] = '\0';
	free(*file);
	*file = NULL;
	return (0);
}
