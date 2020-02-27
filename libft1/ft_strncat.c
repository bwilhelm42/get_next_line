/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:55:04 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/19 18:22:01 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;

	i = ft_strlen(dest);
	while (n-- > 0)
	{
		dest[i] = *src;
		if (*src == '\0')
			return (dest);
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
