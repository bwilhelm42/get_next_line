/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:21:19 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/24 20:58:06 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = (long)n;
	len = num_len(num);
	if (num < 0)
		len += 1;
	str = ft_strnew(len + 1);
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	if (num == 0)
		str[0] = '0';
	while (len-- > 0 && num != 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
