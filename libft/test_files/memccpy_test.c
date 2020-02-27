#include "../libft.h"
#include <stdio.h>

int		main()
{
	char str[40] = "1dkglne398sn;apodensdj2345";
	char str_dest;
	
	ft_memccpy(&str_dest, str, ';', 20);
	printf("%s\n", &str_dest);
	return (0);
}
