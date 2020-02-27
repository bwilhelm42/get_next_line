/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:23:38 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/19 21:21:13 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t j;
	size_t ret;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ret = dst_len + src_len;
	while (j + dst_len < size)
	{
		if (src[j] == '\0' || j + dst_len + 1 == size)
		{
			dst[j + dst_len] = '\0';
			return (ret);
		}
		dst[j + dst_len] = src[j];
		j++;
	}
	return (src_len + size);
}
