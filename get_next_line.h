/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:28:35 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/29 18:37:37 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 214783646
# define INT_MAX 2147483647
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
int		find_newline(char **file, char **line);
void	ft_set_realloc(char **str, int new_pos);

#endif
