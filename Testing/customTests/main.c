#include "test.h"
#include <stdio.h>

int main(void)
{
	//pthread_t *thread = malloc(sizeof(pthread_t) * 100);

	//printf("SIZET = %zu\n", ((size_t)-1));
	int i = 0;
	while (i < 1)
	{
		malloc(30000000000);
		i++;
	}
	ft_putstr("Done");
	show_alloc_mem();
	// run_test_malloc();
	// run_test_realloc();
	// run_test_mixed();

	// int i = 0;
	// while (i < 100) {
	// 	if (pthread_create(thread + i, NULL, run_test_thread, NULL)) {
	// 		printf("Error pthread");
	// 		return EXIT_FAILURE;
	// 	}
	// 	// if (pthread_join(thread[i], NULL)) {
	// 	// 	printf("error pthread join");
	// 	// 	return EXIT_FAILURE;
	// 	// }
	// 	i++;
	// }
	//
	//run_test_rlimit(); // Always at the end
}
