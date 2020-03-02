#include "malloc.h"

void	*next_block_addr(t_heap *heap)
{
	//we dont verify first coz cant be null, we initialize when we crate a heap
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
	t_heap* heap_chain;
	t_heap *new_heap;
	
	heap_chain = first_heap(0);
	while (heap_chain && heap_chain->next)
		heap_chain = heap_chain->next;
		//addr = mmap(NULL, length + offset - pa_offset, PROT_READ,
                //MAP_PRIVATE, fd, pa_offset);
	//if ((new_heap =mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0)) == NULL)//si soucis essayer SHARED
	//Pnser quer pour les tiny small on verify la place a chaque fois mais le large il faut malloc pour le malloc + p meta et b meta
	if ((new_heap = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return NULL;
	if (heap_chain)
		heap_chain->next = new_heap;
	else
	{
		t_heap **ref_first = first_origin();
		*ref_first = new_heap;
		//Attention ici verifyier que ca a modifier la valeur de la static, (du pointer). si non il faut une etoile de plus
		//Ca a lair bon
		// printf("%p\n", new_heap);
		// printf("%p\n", first_heap());
		// printf("Here\n");
	}

	return new_heap;
}

//When we create a new heap, we must also create a block for the current malloc and return its pointer
void* new_heap(size_t size)
{
	t_heap *heap = NULL;

	if ((heap = create_heap(size)) == NULL)
		return NULL;
	prepare_heap(heap, size);
	return (create_block(heap, size, heap + 1));
}
