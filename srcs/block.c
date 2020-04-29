#include "../includes/malloc.h"

void init_block(t_block *block, size_t size)
{
    block->freed = 0;
    block->data_size = size;
    block->next = NULL;
    //printf("next block after creation %p\n", block->next);
}


void    add_block_heap(t_heap *heap, t_block *new_block)
{
	t_block		*ptr;

	ptr = heap->blocks;
    
	if (!ptr)
    {
		heap->blocks = new_block;
        printf("Added block but block is at %p and it is refered by %p\n", new_block, heap->blocks);
    }
	else
	{
		while (ptr->next)
            ptr = ptr->next;
        ptr->next = new_block;
        printf("Added block but block is at %p and it is refered by %p\n", new_block, ptr->next);
	}
    //to remove debug
    size_t debugX = heap->free_size;
	heap->free_size -= B_META_SIZE + new_block->data_size;
    if (debugX > heap->free_size)
        printf("Problem of cast because < 0 (size_t)");
}

t_block	*create_block(t_heap *heap, size_t size, void *addr)
{
	t_block *block;
	t_block *new_block;
    
    block = heap->blocks;
    new_block = (t_block*)addr;
	while (block && block->next)
		block = block->next;
    
    // if (heap->blocks == NULL)
    //     printf("NULLL\n");
    //printf("first block heap adress = %p and curr block = %p and first block from curr heap = %p\n", first_heap()->blocks, new_block, heap->blocks);
    
    //init_block(new_block, size);
    
    // printf("eap block = %p\n", heap->blocks);
    add_block_heap(heap, new_block);
    init_block(new_block, size);
    // printf("curr block %p and space addr = %p\n", new_block, addr);
    // printf("curr heap = %p and first page heap = %p\n", heap, first_heap());
    // printf("first block heap adress = %p and curr block = %p and first block from curr heap = %p\n", first_heap()->blocks, new_block, heap->blocks);
	//printf("is it free  %d\n", first_heap()->blocks->freed);
    return (new_block);
}
