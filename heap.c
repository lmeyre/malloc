#include "includes.h"

void	*next_block_addr(t_heap *heap)
{
	//first cant be null, we initialize when we crate a heap
	t_block *block;

	block = heap->blocks;
	while (block->next)
		block = block->next;
	return (block + block->data_size + 1);
}

void	prepare_heap(t_heap* heap, size_t size)
{
	heap->total_size = size;
	heap->type = return_type(heap->total_size);
	heap->free_size = heap->total_size;
	heap->next = NULL;
	heap->blocks = NULL;
}

t_heap	*create_heap(size_t size)
{
	t_heap* heap;
	
	heap = first_heap();
	while (heap && heap->next)
		heap = heap->next;
	//if (heap = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0) == NULL)//si soucis essayer SHARED
		return NULL;
	return heap;
}

//When we create a new heap, we must also create a block for the current malloc and return its pointer
void* new_heap(size_t size)
{
	t_heap *heap;

	if ((heap = create_heap(size)) == NULL)
		return NULL;
	prepare_heap(heap, size);
	return (create_block(heap, size, heap + 1));
}
