#include "../libft.h"
#include <stdio.h>

int		main()
{
	char *str = NULL;
	char *str_dest = NULL;
	
	memcpy(str_dest, str, 4);
	printf("%s\n", str_dest);
	return (0);
}
