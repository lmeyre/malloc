#include "includes.h"

void init_block(t_block *block, size_t size)
{
    block->freed = 0;
    block->data_size = size;
    block->next = NULL;
}
//attention on cree pas nos block nimporte ou, on doit caster une adresse en pointeur sur block, 
//ptet pareil pour les heap ?

t_block	*create_block(t_heap *heap, size_t size, void *addr)
{
	t_block *block;
	t_block *newBlock;

    block = heap->blocks;
    newBlock = (t_block*)addr;
	while (block && block->next)
		block = block->next;
    init_block(block, size);
    if (block == NULL)
        heap->blocks = newBlock;
    else
        block->next = newBlock;
    heap->free_size -= size + B_META_SIZE;
    if(heap->free_size < 0)
        printf("PROBLEM");
    return (newBlock);
}