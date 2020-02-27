#include "../libft.h"
#include <stdio.h>

int		main()
{
	char str[12] = "Hello world";
	char *temp;

	printf("%s\n", str);
	temp = memset(&str[3], '*', 4);
	printf("memset says: %s\n", temp);
	temp = ft_memset(&str[3], '*', 4);
	printf("ft_memset says: %s\n", temp);

	char stra[19] = "Goodbye cruel world";
	printf("%s\n", stra);
	temp = memset(&str[3], '*', 4);
	temp = memset(&stra[0], ' ', 2);
	printf("memset says: %s\n", temp);
	temp = ft_memset(&stra[0], ' ', 2);
	printf("ft_memset says: %s\n", temp);

	char strb[43] = "This is more than just a testcase... or not";
	printf("%s\n", strb);
	temp = memset(&str[3], '*', 4);
	temp = memset(&strb[6], '-', 8);
	printf("memset says: %s\n", temp);
	temp = ft_memset(&strb[6], '-', 8);
	printf("ft_memset says: %s\n", temp);
}
