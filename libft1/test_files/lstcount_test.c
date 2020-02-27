#include "../libft.h"
#include <stdio.h>

int		main()
{
	char *str = "hello";
	size_t nb = 5;
	t_list *lst = ft_lstnew(str, nb);

	lst->next = ft_lstnew(str, nb);
	lst->next->next = ft_lstnew(str, nb);
	ft_putnbr(ft_lstcount(lst));
	return (0);
}
