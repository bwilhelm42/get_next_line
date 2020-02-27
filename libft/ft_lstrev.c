/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:16:29 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/26 10:08:16 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list **head)
{
	t_list *prev;
	t_list *future;
	t_list *cur;

	cur = *head;
	prev = NULL;
	while (cur != NULL)
	{
		future = cur->next;
		cur->next = prev;
		prev = cur;
		cur = future;		
	}
	*head = prev;
	return (*head);
}
