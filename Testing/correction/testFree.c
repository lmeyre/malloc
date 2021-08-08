#include "../../includes/malloc.h"

int	main(void)
{
	int		i;
	char	*addr;

    addr = (char*)malloc(1200000);
    addr[0] = 42;
    free(addr);
}