/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:34:09 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/24 20:56:35 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cut_spaces(char *s)
{
	int start;
	int end;

	start = 0;
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\t'
			|| s[start] == '\n' || s[start] == '\0')
	{
		if (start == end)
			return (0);
		start++;
	}
	while (s[end - 1] == ' ' || s[end - 1] == '\t'
			|| s[end - 1] == '\n')
		end--;
	return (end - start);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	char	*ptr;

	ptr = (char*)s;
	i = cut_spaces(ptr);
	if ((str = (char*)malloc(i + 1)) == NULL)
		return (NULL);
	while ((*ptr == ' ' || *ptr == '\n' || *ptr == '\t')
			&& *ptr != '\0')
		ptr++;
	if (i)
		ft_strncpy(str, ptr, i);
	str[i] = '\0';
	return (str);
}
