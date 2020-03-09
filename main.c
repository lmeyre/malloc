#include "malloc.h"

//#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
//#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)
//# define P_META_SIZE			sizeof(t_page)
//# define B_META_SIZE			sizeof(t_block)

int main(void)
{
    // SYSTEM_INFO si;
    // GetSystemInfo(&si);
    // printf("The page size for this system is %u bytes.\n", si.dwPageSize);
    // int total = 0;
    // int heapSize = SMALL_HEAP_ALLOCATION_SIZE;
    // int blockSize = SMALL_BLOCK_SIZE;
    // int bmeta = B_META_SIZE;
    // int realsize = blockSize + bmeta;

    // int spaceLeft = heapSize / realsize;
    // printf("meta = %d\n", bmeta);
    // printf("place left for = %d\n", spaceLeft);
    printf("Tiny = %d, Small = %d\n", TINY_HEAP_ALLOCATION_SIZE, SMALL_HEAP_ALLOCATION_SIZE);
    (void)malloc(500);
    printf("Malloc n2\n");
    (void)malloc(500);
    printf("Malloc n3\n");
    (void)malloc(500);
    return 0;
}