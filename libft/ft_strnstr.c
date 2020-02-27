/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:08:41 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/23 14:52:55 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*big;
	char	*small;
	int		i;

	big = (char*)haystack;
	small = (char*)needle;
	if (*small == '\0')
		return (big);
	while (*big != '\0' && len > 0)
	{
		i = 0;
		while ((big[i] == small[i] && len - i > 0))
		{
			i++;
			if (small[i] == '\0')
				return (big);
		}
		big++;
		len--;
	}
	return (NULL);
}
