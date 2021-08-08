#include "../../includes/malloc.h"

int	main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		ft_putnbr(i);
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
}