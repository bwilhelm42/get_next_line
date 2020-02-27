/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:28:16 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/26 19:46:12 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int	line_count;
	static int	total_read;
	int			cur_read;
	char		temp;

	cur_read = total_read;
	new_lines = 0;
	temp = 'a';
	while (temp != '\0' && read(fd, &temp, 1))
	{
		if (++cur_read <= total_read)
			continue ;
		if (temp = '\n')
			temp = '\0';
		add_char(line, temp, total_read - cur_read);
	}
}	

void	add_char(char **line, char *temp, int buf)
{
	char *ptr;

	ptr = (char*)ft_memalloc(buf + 2);
	ft_strcpy(ptr, *line);
	ft_strlcat(ptr, temp, 1);
	if (ft_strlen(*line) > 1)
		free(*line);
	*line = ptr;
}
