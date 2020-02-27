/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:59:11 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/22 12:28:23 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	temp[len + 1];
	size_t			i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		temp[i] = ((unsigned char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((unsigned char*)dest)[i] = temp[i];
		i++;
	}
	return (dest);
}
