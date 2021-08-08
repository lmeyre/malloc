/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"


void	*search_free_block(size_t size, t_data_type size_type)
{
	t_heap* heap;
	
	//ft_putstr("Looking for a free block in heap\n");
	heap = first_heap();
	while (heap)
	{
		//ft_putstr("found heap\n");
		if (heap->type == size_type)
		{
			// ft_putstr("valid heap\n");
			// if (heap->first_block == NULL)
			// 	ft_putstr("First block of the heap is null\n");
			t_block* block = heap->first_block;
			while (block)
			{
				//printf("found a block = %p, its free ? = %d\n", block, block->freed);
				//on essai de voir si ya la place pour la data + meta, pour diviser se block en 2 block, dont 1 qui a la meta + pile la size
				//le seul soucis c'est que dans le cas ou le bloc fait pile la taille qu'on veut,  comme on essai d'en faire un autre, et qu'on prevoit pour la meta (vu qu'on divise)
				//ca va pas marcher, mais c'est ok
				if (block->free == 1 && block->data_size >= B_META_SIZE + size)
				{
					//ft_putstr("Found heap with a block empty\n");
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
	
	#ifdef DEBUG_MALLOC
	//if (debug == 1)
		ft_putstr("Looking for a heap to use for the malloc");
	#endif
	//ft_putstr("Looking for a room in a heap\n");
	//heap = g_heap_origin;
	heap = first_heap();
	while (heap)
	{
		if (heap->type == type && heap->free_size >= required_free_size)
		{
			#ifdef DEBUG_MALLOC
			//if (debug == 1)
				ft_putstr("Found a non full heap to use");
			#endif
			return heap;
		}
		heap = heap->next;
	}
	//if no heap found, make a new one
	if (!(heap = new_heap(size, type)))
		return NULL;
	#ifdef DEBUG_MALLOC
	//if (debug == 1)
		ft_putstr("Found no free heap, creating a new one");
	#endif
	return heap;
}

//Quand on free un block, il existe toujours mais il est dispo, si on doit malloc un ptr
//et qu'on trouve un de ces blocks free qui a une taille sup ou egal au ptr size
// on file cet endroit pour recycler


void* malloc(size_t size)
{
	void* ptr;
	t_block	*block;
	t_heap	*heap;

	#ifdef DEBUG_MALLOC
		ft_putstrn("\nStarting malloc of type ");// Useful to know if we use our malloc or real one
	#endif
	ptr = NULL;
	if (size <= 0)
		return NULL;

	size = (size + 15) & ~15;//padding
	t_data_type size_type = return_type(size);
	#ifdef DEBUG_MALLOC
		if (size_type == TINY)
			ft_putstr("TINY");
		else if (size_type == SMALL)
			ft_putstr("SMALL");
		else
			ft_putstr("LARGE");
		ft_putstrn("Size is ");
		ft_putnbr(size);
	#endif
	if ((block = search_free_block(size, size_type)) != NULL)
	{
		#ifdef DEBUG_MALLOC
			ft_putstr("Using existing empty block");
		#endif
		return (use_free_block(block, size));
	}
	//if not, get a heap
	if (!(heap = (t_heap*)search_free_heap(size, size_type))) // if no free, will create ad return new one
		return (NULL);

	block = create_block(heap, size);
	return ((void*)block + B_META_SIZE);
}