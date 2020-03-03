#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"

int		main(int ac, char **av)
{
	int i;
	char *str;
	int ret;

	(void)ac;
	str = NULL;
	i = open(av[1], O_RDONLY);
	while ((ret = get_next_line(i, &str)))
	{
		ft_putnbr(ret);
		ft_putendl(str);
		free(str);
		
	}
	ft_putnbr(ret);
	ft_putstr(str);
	return (0);
}
