#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"

int		main(int ac, char **av)
{
	int i;
	char *str;
	
	(void)ac;
	str = NULL;
	i = open(av[1], O_RDONLY);
	get_next_line(i, &str);
	write(1, str, 26);
	ft_putstr(str);
	return (0);
}
