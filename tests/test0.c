#include "../includes/malloc.h"

int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	//Attention ca n'appelle pas le bon malloc de base, trouver comment lier
	printf("Going to test : \n");

	printf("Tiny = %d, Small = %d\n", TINY_HEAP_ALLOCATION_SIZE, SMALL_HEAP_ALLOCATION_SIZE);
    (void)malloc(500);
    printf("Malloc n2\n");
    (void)malloc(500);
    printf("Malloc n3\n");
    (void)malloc(500);
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	return (0);
}
