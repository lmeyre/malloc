#ifndef MALLOC_H
#define MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/mman.h>
# include <stdint.h>
# include <sys/types.h>
 #include <sys/resource.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "limits.h"
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
//could make a method to return prev block/heap to avoid stocking it and maximise space
//en parler en corr ? -> a en parler
    struct s_block* next;
    size_t          data_size;
    int             freed;
} t_block;

typedef struct s_heap
{
    //struct s_heap*  prev;//meme comment que pour block prev
    struct s_heap*  next;
    t_block*        first_block;// on pourrait l'enlever et acceder au ptr block en allant a heap + heap meta size, si on le fait en parler en correc
    size_t          total_size;
    size_t          free_size;
    t_data_type     type;
    int count;
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
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)  //128
#define SMALL_HEAP_ALLOCATION_SIZE (32 * getpagesize())//ou 16 ? on avait mit 16 mais on a mit comme jterazz
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128) // 512
# define H_META_SIZE			sizeof(t_heap)
# define B_META_SIZE			sizeof(t_block)


t_heap*     first_heap();
t_heap      **first_origin();
t_heap*     new_heap(size_t size, t_data_type type);
t_data_type return_type(size_t size);
t_block	    *create_block(t_heap *heap, size_t size);
void        *use_free_block(t_block *block, size_t size);
void        try_fusion_block(t_block *block, t_heap *heap)
void        clear_heap_end(t_heap *heap, t_block *block)
void	    clear_heap(t_heap heap)
//void	*next_block_addr(t_heap *heap);
void*       malloc(size_t size);
void	    ft_putnbr(int n);
void	    ft_putstr(char const *s);
void	    ft_bzero(void *s, size_t n);
void        free(void *ptr);
void        *realloc(void *ptr, size_t size);

//void* search_free_block(size_t size);

#endif