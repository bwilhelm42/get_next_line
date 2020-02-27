#include "../libft.h"
#include <stdio.h>

void	func(t_list *elem)
{
	elem->content = "hello";	
}

int		main()
{
	char *str = "test";
	t_list *lst = ft_lstnew(str, 4);

	lst->next = ft_lstnew(str, 4);
	lst->next->next = ft_lstnew(str, 4);
	ft_lstiter(lst, &func);
	if (!strcmp(str, lst->content))
		printf("1: A match, we have\n");
	if (!strcmp(str, lst->next->content))
		printf("2: A match, we have\n");
	if (!strcmp(str, lst->next->next->content))
		printf("2: A match, we have\n");
	printf("elem1: %s\nelem2: %s\nelem3: %s\n", lst->content, lst->next->content, lst->next->next->content);
	return (0);
}
