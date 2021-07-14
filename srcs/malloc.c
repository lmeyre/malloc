#include "../includes/malloc.h"


void	*search_free_block(size_t size)
{
	t_heap* heap;
	
	ft_putstr("Looking for a free block in heap\n");
	heap = first_heap();
	while (heap)
	{
		ft_putstr("found heap\n");
		if (heap->type == return_type(size))
		{
			ft_putstr("valid heap\n");
			if (heap->blocks == NULL)
				ft_putstr("First block of the heap is null\n");
			t_block* block = heap->blocks;
			while (block)
			{
				//printf("found a block = %p, its free ? = %d\n", block, block->freed);
				if (block->freed && block->data_size <= size)
				{
					ft_putstr("Found heap with a block empty\n");
					return (block);
				}
				block = block->next;
			}
		}
		heap = heap->next;
	}
	return NULL;
}

void *search_free_heap(size_t size, t_data_type type)
{
	t_heap* heap;
	//extern t_heap *g_heap_origin;
	size_t required_free_size = size + B_META_SIZE;
	
	ft_putstr("Looking for a room in a heap\n");
	//heap = g_heap_origin;
	heap = first_heap();
	while (heap)
	{
		//ft_putstr("found heap\n");
		//Que se passe il si la heap a 100 de free size en 2 x, genre 50 et 50
		//Et qu'on cherche a placer un malloc de 75 ?
		//en fait on doit essayer que quand on free un block, on replace ceux apres colle a ceux d'avant pour pas avoir de trou
		if (heap->type == type && heap->free_size >= required_free_size)
		{
			ft_putstr("valid heap\n");
			return heap;
		}
		heap = heap->next;
	}
	//if no heap found, make a new one
	if (!(heap = new_heap(size, type)))
		return NULL;
	return heap;
}

//Quand on free un block, il existe toujours mais il est dispo, si on doit malloc un ptr
//et qu'on trouve un de ces blocks free qui a une taille sup ou egal au ptr size
// on file cet endroit pour recycler


void* malloc(size_t size)
{
	void* ptr;

	//return NULL;
	ft_putstr("Starting malloc");// Useful to know if we use our malloc or real one
	ft_putnbr(size);
	ptr = NULL;
	if (size <= 0)
		return NULL;

	size = (size + 15) & ~15; // padding necessary maybe ? 
	//if free block, assign it
	t_data_type size_type = return_type(size);
	if ((ptr = search_free_block(size)) != NULL)
		return ((void*)ptr + B_META_SIZE);
	//if not, get a heap
	if (!(ptr = (t_heap*)search_free_heap(size, size_type))) // if no free, will create ad return new one
		return (NULL);
	//Assign the block in the heap here
	
	ft_putstr("MARK");
	return create_block(ptr, size);
	return (ptr + B_META_SIZE);//???
}