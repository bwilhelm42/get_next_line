/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:47:08 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/19 13:46:21 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *temp;

	temp = (char*)s;
	while (n-- > 0)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	return (NULL);
}
