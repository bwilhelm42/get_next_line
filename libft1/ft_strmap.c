/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:40:42 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/21 22:02:33 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*ref;

	ref = (char*)s;
	str = (char*)malloc(ft_strlen(ref) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (ref[i] != '\0')
	{
		str[i] = (*f)(ref[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
