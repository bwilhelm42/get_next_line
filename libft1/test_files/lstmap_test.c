#include "../libft.h"
#include <stdio.h>

t_list	*func(t_list *elem)
{
	elem->content = "Wahoo";
	return (elem);
}

void	print_func(t_list *elem)
{
	ft_putstr(elem->content);
}

int		main()
{
	char *str = "test";
	t_list *lst = ft_lstnew(str, 4);
	t_list *map;
	t_list *empty = NULL;

	lst->next = ft_lstnew(str, 4);
	lst->next->next = ft_lstnew(str, 4);
	map = ft_lstmap(empty, &func);
//	ft_lstiter(map, &print_func);
	return (0);
}
