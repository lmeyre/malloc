#include "includes.h"


void	*search_free_block(size_t size)
{
	t_heap* heap;
	
	heap = first_heap();
	while (heap)
	{
		if (heap->type == return_type(size))
		{
			t_block* block = heap->blocks;
			while (block)
			{
				if (block->freed && block->data_size <= size)
					return (block);
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
			return create_block(heap, size, next_block_addr(heap));
		}
		heap = heap->next;
	}
}

//Quand on free un block, il existe toujours mais il est dispo, si on doit malloc un ptr
//et qu'on trouve un de ces blocks free qui a une taille sup ou egal au ptr size
// on file cet endroit pour recycler

void* mallocX(size_t size)
{
	void* ptr;
	
	ptr = NULL;
	if (size <= 0)
		return NULL;
	if (size <= SMALL_BLOCK_SIZE)
		ptr = search_free_block(size);//block free
	if (ptr == NULL)
		ptr = search_free_heap(size);//heap with size to add more block
	if (ptr == NULL)
		ptr = new_heap(size);//new heap
	return ptr;
}