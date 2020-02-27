#include "../libft.h"
#include <stdio.h>
#include <strings.h>

int		main()
{
	char str[12] = "Hello world";
	ft_bzero(&str[3], 4);
	printf("ft_bzero says: %s\n", str);

	char stra[19] = "Goodbye cruel world";
	ft_bzero(&stra[0], 2);
	printf("ft_bzero says: %s\n", stra);

	char strb[43] = "This is more than just a testcase... or not";
	ft_bzero(&strb[6], 8);
	printf("ft_bzero says: %s\n", strb);
}
