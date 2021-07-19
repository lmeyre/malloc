#include <stdio.h>
#include "./test.h"

static void test_free_1(void) 
{
	void *test = malloc(10);
	void *test2 = malloc(10);
	void *test3 = malloc(10);
	free(test);
	free(test2);
	free(test3);
}

static void test_realloc_mix(void) 
{
	void *test = malloc(10);
	void *test2 = malloc(10);
	void *test3 = malloc(10);

	free(test);
	test2 = realloc(test2, 10);
	test2 = realloc(test2, 11);
	test2 = realloc(test2, 9);
	free(test2);
	free(test3);
}

static void test_realloc_mix_2(void) 
{
	void *test = malloc(10);
	test = realloc(test, 11);
	test = realloc(test, 9);
	test = realloc(test, 8);
}

void test_show_alloc_mem_ex(void) 
{
	char *test = (char*) malloc(20);
	char *test2 = (char*) malloc(22);
	test[0] = 5;
	test[1] = 5;
	test[2] = 5;
	test[3] = 5;
	test[4] = 5;
	test[5] = 5;
	//~~show_alloc_mem_hex();
	free(test);
	free(test2);
}

void run_test_mixed(void)
{
	// test_show_alloc_mem_ex();
	test_free_1();
	test_realloc_mix();
	test_realloc_mix_2();
}
