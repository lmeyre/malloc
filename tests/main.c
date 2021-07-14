#include "../includes/malloc.h"
#include <sys/sysinfo.h>

//#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
//#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)
//# define P_META_SIZE			sizeof(t_page)
//# define B_META_SIZE			sizeof(t_block)


// On a reussit a override malloc avec le notre en faisant ca , apres le make, mais avant le clang/gcc du main + lib
// #!/bin/sh
// export DYLD_LIBRARY_PATH="."
// export DYLD_INSERT_LIBRARIES="libft_malloc.so"
// export DYLD_FORCE_FLAT_NAMESPACE="1"
// $@

// REAL PRINTF CALL MALLOC AND WE OVERRIDE IT SO FOR NICE TEST DONT USE PRINTF
int main(void)
{
    // SYSTEM_INFO si;
    // GetSystemInfo(&si);
    //printf("The page size for this system is %u bytes.\n", si.dwPageSize);
    //int total = 0;


    // int heapSize = SMALL_HEAP_ALLOCATION_SIZE;
    // int blockSize = SMALL_BLOCK_SIZE;
    // int bmeta = B_META_SIZE;
    // int realsize = blockSize + bmeta;

    // int spaceLeft = heapSize / realsize;
    // printf("\n\\\\\\\\\\\\\\\\ SPECIAL DEBUG \\\\\\\\\\\\\\n");
    // printf("meta = %d\n", bmeta);
    // printf("place left for = %d\n", spaceLeft);// pas sur pourquoi la space left c'est pas lputot blocksize - meta ?
    // printf("Tiny = %d, Small = %d\n", TINY_HEAP_ALLOCATION_SIZE, SMALL_HEAP_ALLOCATION_SIZE);
	// printf("%d\n", getpagesize());
    // printf("%d is tiny block size, %d is small\n", TINY_BLOCK_SIZE, SMALL_BLOCK_SIZE);

    //return 0;

    (void)malloc(500);
    //printf("Malloc n2\n");
    // (void)malloc(500);
    // printf("Malloc n3\n");
    // (void)malloc(500);

    // while (i < 1024)
	// {
	// 	addr = (char*)malloc(1024);
	// 	addr[0] = 42;
	// 	i++;
	// }
    return 0;
}