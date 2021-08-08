#include "../../includes/malloc.h"

int	main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 250)
	{
		ft_putnbr(i);
		addr = (char*)malloc(4100);
		addr[0] = 42;
		free(addr);
		i++;
	}
}