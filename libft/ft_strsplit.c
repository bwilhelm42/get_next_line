/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:30:48 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/24 13:49:31 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char **str, char c)
{
	int i;

	i = 0;
	while ((*str)[i] == c && (*str)[i] != '\0')
		i++;
	*str += i;
	while ((*str)[i] != c && (*str)[i] != '\0')
		i++;
	return (i);
}

static void	move_ptr_next_word(char **str, char c)
{
	while (**str != c && **str != '\0')
		(*str)++;
}

static int	word_count(char *str, char c)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			return (i);
		i++;
		while (*str != c && *str != '\0')
			str++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*str_s;
	char	**str;
	int		wl;
	int		i;
	int		wc;

	i = 0;
	str_s = (char*)s;
	str = NULL;
	wc = word_count(str_s, c);
	str = (char**)malloc(wc * sizeof(char*) + 1);
	while (wc-- > 0)
	{
		wl = word_len(&str_s, c);
		if (wl == 0)
			return (str);
		str[i] = ft_strnew((size_t)wl + 1);
		ft_strncpy(str[i], str_s, wl);
		move_ptr_next_word(&str_s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
