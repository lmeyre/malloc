#ifndef MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/mman.h>
//#include <windows.h> // to remove  

typedef enum e_data_type
{
    TINY,
    SMALL,
    LARGE
}           t_data_type;

typedef struct s_block
{
    //struct s_block* prev;
    struct s_block* next;
    size_t          data_size;
    int             freed;
} t_block;

typedef struct s_heap
{
    //struct s_heap* prev;//check if needed (check every field)
    struct s_heap* next;
    t_block*    blocks;
    size_t          total_size;
    size_t          free_size;
    t_data_type     type;
} t_heap;

//#define HEAP_SHIFT(start) ((void *)start + sizeof(t_heap))
//#define BLOCK_SHIFT(start) ((void *)start + sizeof(t_block))

//tmp coz windows sucks

// #define TINY_HEAP_ALLOCATION_SIZE (4 * 4069)
// #define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
// #define SMALL_HEAP_ALLOCATION_SIZE (16 * 4096)
// #define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)
// # define P_META_SIZE			sizeof(t_page)
// # define B_META_SIZE			sizeof(t_block)

#define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)
# define P_META_SIZE			sizeof(t_heap)
# define B_META_SIZE			sizeof(t_block)


t_heap* first_heap();
void* new_heap(size_t size);
t_data_type return_type(size_t size);
t_block	*create_block(t_heap *heap, size_t size, void *addr);
void	*next_block_addr(t_heap *heap);
void* malloc(size_t size);
t_heap **first_origin();

//void* search_free_block(size_t size);
    
# define MALLOC_H

#endif