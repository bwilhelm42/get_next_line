/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:04:34 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/29 18:30:34 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*file;
	int			ret;
	int			i;

	i = 0;
	if (!line || BUFF_SIZE <= 0 || BUFF_SIZE >= INT_MAX)
		return (-1);
	if (file == NULL)
		file = (char*)malloc(BUFF_SIZE + 1);
	else
	{
		i = ft_strlen(file);
		if (find_newline(&file, line))
			return (1);
	}
	while ((ret = read(fd, &file[i], BUFF_SIZE)))
	{
		if (find_newline(&file, line))
			return (1);
		if (*file != '\0')
			i += BUFF_SIZE;
	}
	find_newline(&file, line);
	return (0);
}

int		find_newline(char **file, char **line)
{
	char	*nl;
	int		line_len;
	int		i;

	i = 0;
	while ((*file)[i] == '\n')
		i++;
	if (i > 0)
		ft_set_realloc(file, i);
	if (!(nl = ft_strchr(*file, '\n')))
	{
		ft_set_realloc(file, 0);
		return (0);
	}
	line_len = ft_strclen(*file, '\n');
	*line = (char*)ft_memalloc(line_len + 1);
	ft_strncpy(*line, *file, line_len);
	ft_set_realloc(file, line_len + 1);
	return (1);
}

void	ft_set_realloc(char **str, int new_pos)
{
	char	*temp;
	int		len;

	len = ft_strlen(&(*str)[new_pos]);
	if (new_pos == 0)
		temp = (char*)ft_memalloc(len + BUFF_SIZE + 1);
	else
		temp = (char*)ft_memalloc(len + 1);
	ft_strcpy(temp, &(*str)[new_pos]);
	free(*str);
	*str = temp;
}
