/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:28:16 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/27 09:36:57 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
//	static int	line_count;
	static int	total_read;
	int			cur_read;
	char		temp;

	cur_read = total_read;
	temp = 'a';
	while (temp != '\n' && read(fd, &temp, 1))
	{
		if (++cur_read <= total_read)
			continue ;
		if (temp == '\n') 
			return (0);
		add_char(line, temp, cur_read);
	}
	return (0);
}	

void	ft_appendchar(char *dest, char src)
{
	int i;

	i = ft_strlen(dest);
	dest[i] = src;
}

void	add_char(char **line, char temp, int buf)
{
	char *ptr;

	ptr = (char*)ft_memalloc(buf + 2);
	if (*line == NULL)
		*ptr = temp;
	else
	{
		ft_strcpy(ptr, *line);
		ft_appendchar(ptr, temp);
		free(*line);
	}
	*line = ptr;
}
