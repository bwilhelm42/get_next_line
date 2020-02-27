#include "../libft.h"
#include <stdio.h>

int		main()
{
	char *str = "this is a sentence";
	unsigned int start = 4;
	size_t len = 4;

	printf("%s\n", ft_strsub(str, start, len));
}
