/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:00:44 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/21 21:51:35 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	temp = (char*)s1;
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (temp[i] != '\0')
	{
		str[i] = temp[i];
		i++;
	}
	temp = (char*)s2;
	while (temp[j] != '\0')
	{
		str[i + j] = temp[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
