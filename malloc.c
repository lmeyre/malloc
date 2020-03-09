#include "malloc.h"


void	*search_free_block(size_t size)
{
	t_heap* heap;
	
	heap = first_heap();
	while (heap)
	{
		printf("found heap\n");
		if (heap->type == return_type(size))
		{
			printf("valid heap\n");
			t_block* block = heap->blocks;
			while (block)
			{
				printf("%p\n", block);
				printf("found a block = %p, its free ? = %d\n", block, block->freed);
    			printf("next = %p\n", block->next);
				if (block->freed && block->data_size <= size)
				{
					printf("Found heap with a block empty\n");
					return (block);
				}
				block = block->next;
			}
		}
		heap = heap->next;
	}
	return NULL;
}

void *search_free_heap(size_t size)
{
	t_heap* heap;
	
	heap = first_heap();
	while (heap)
	{
		if (heap->type == return_type(size) && heap->total_size > (size + B_META_SIZE))
		{
			printf("Found heap with space\n");
			return create_block(heap, size, next_block_addr(heap));
		}
		heap = heap->next;
	}
	return NULL;
}

//Quand on free un block, il existe toujours mais il est dispo, si on doit malloc un ptr
//et qu'on trouve un de ces blocks free qui a une taille sup ou egal au ptr size
// on file cet endroit pour recycler

void* malloc(size_t size)
{
	void* ptr;
	
	ptr = NULL;
	if (size <= 0)
		return NULL;
	if (size <= (size_t)SMALL_BLOCK_SIZE)
		ptr = search_free_block(size);//block free
	if (ptr == NULL)
		ptr = search_free_heap(size);//heap with size to add more block
	if (ptr == NULL)
		ptr = new_heap(size);//new heap, return first block
	
    printf("Fin %p\n", ((t_block*)ptr)->next);
	//printf();
	return (ptr + B_META_SIZE);
}