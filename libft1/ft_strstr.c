/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:32:27 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/19 22:02:24 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*big;
	char	*small;
	int		i;

	big = (char*)haystack;
	small = (char*)needle;
	if (*needle == '\0')
		return (big);
	while (*big != '\0')
	{
		i = 0;
		while (big[i] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return (big);
		}
		big++;
	}
	return (NULL);
}
