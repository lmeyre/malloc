#include "../../includes/malloc.h"

int	main(void)
{
	// malloc(1024);
	// malloc(1024 * 32);
	// malloc(1024 * 1024);
	// malloc(1024 * 1024 * 16);
	// malloc(1024 * 1024 * 128);
	//show_alloc_mem();


	//custom version
	malloc(1024 * 1024 * 128);
	malloc(102);
	malloc(1024);
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	show_alloc_mem();
	return (0);
}
