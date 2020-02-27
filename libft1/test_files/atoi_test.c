#include "../libft.h"
#include <stdio.h>

int		main()
{
	ft_putnbr(atoi("99999999999999999999999998"));
	write(1, "\n", 1);
	ft_putnbr(ft_atoi("99999999999999999999999998"));
	write(1, "\n", 1);
	printf("%llu\n", atoi("99999999999999999999999998"));
	return (0);
}	
