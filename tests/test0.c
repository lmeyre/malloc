#include "../includes/malloc.h"

int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	printf("Going to test : \n");
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	return (0);
}
