#ifndef MALLOC_TEST
#define MALLOC_TEST

#include "../../includes/malloc.h"

#define M1 (1024 * 1024)

void run_test_malloc(void);
void run_test_realloc(void);
void run_test_mixed(void);
void show_heap_list();
void run_test_rlimit();

#endif
