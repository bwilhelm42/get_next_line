#include "../libft.h"

void	print_elem(t_list *elem)
{
	ft_putendl(elem->content);
}

int		main()
{
	t_list *lst = ft_lstnew("5", 1);

	lst->next = ft_lstnew("4", 1);
	lst->next->next = ft_lstnew("3", 1);
	lst->next->next->next = ft_lstnew("2", 1);
	lst->next->next->next->next = ft_lstnew("1", 1);
	ft_lstiter(lst, &print_elem);
	ft_lstrev(&lst);
	ft_lstiter(lst, &print_elem);
	return (0);
}
