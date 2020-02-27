#include "../libft.h"
#include <stdio.h>

int		main()
{
	t_list *new = ft_lstnew("Hello", 6);

	printf("%s\n%zu\n", new->content *new->content_size);
	return (0);
}
