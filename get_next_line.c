/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:28:04 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/02 19:30:48 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *files[FD_MAX];

	if (fd > FD_MAX)
		return (-1);
	return(got_next_line(&files[fd], fd, line));
}

int		got_next_line(char **file, const int fd, char **line)
{
	long		ret;
	long		index;

	if (BUFF_SIZE > INT_MAX || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (!*file)
	{
		*file = (char*)malloc(BUFF_SIZE + 1);
		(*file)[BUFF_SIZE] = '\0';
	}
	else if (find_nl(file, line))
		return (1);
	index = ft_strlen(*file);
	while ((ret = read(fd, &(*file)[index], BUFF_SIZE)) > 0)
	{
		(*file)[ret] = '\0';
		if (ret < BUFF_SIZE && !find_nl(file, line))
			return (handle_eof(file, line));
		else 
			return (1);
		index += BUFF_SIZE;
	}
	if (ret == -1)
		return (-1);
	return (handle_eof(file, line));
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
		strcpy(temp, &(*file)[i + 1]);
		free(*file);
		*file = temp;
		return (1);
	}
	temp = (char*)malloc((len = ft_strlen(*file)) + BUFF_SIZE + 1);
	temp[len + BUFF_SIZE] = '\0';
	strcpy(temp, *file);
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
