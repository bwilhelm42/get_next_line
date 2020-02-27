#include "../libft.h"
#include <stdio.h>

int		main()
{
	char str[] = "HellZ wZrld!";

	ft_strrep(str, 'o', 'Z');
	printf("%s\n", str);
	return (0);
}
