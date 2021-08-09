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
	
	heap = first_heap();
	while (heap)
	{
		if (heap->type == size_type)
		{
			t_block* block = heap->first_block;
			while (block)
			{
				if (block->free == 1 && block->data_size >= B_META_SIZE + size)
				{
					return (block);
				}
				block = block->next;
			}
		}
		heap = heap->next;
	}
	return NULL;
}

void	*search_free_heap(size_t size, t_data_type type)
{
	t_heap* heap;
	size_t required_free_size;
	
	required_free_size = size + B_META_SIZE;
	#ifdef DEBUG_MALLOC
		ft_putstr("Looking for a heap to use for the malloc");
	#endif
	heap = first_heap();
	while (heap)
	{
		if (heap->type == type && heap->free_size >= required_free_size)
		{
			#ifdef DEBUG_MALLOC
				ft_putstr("Found a non full heap to use");
			#endif
			return heap;
		}
		heap = heap->next;
	}
	if (!(heap = new_heap(size, type)))
		return NULL;
	#ifdef DEBUG_MALLOC
		ft_putstr("Found no free heap, creating a new one");
	#endif
	return heap;
}

void	*malloc(size_t size)
{
	void* ptr;
	t_block	*block;
	t_heap	*heap;

	#ifdef DEBUG_MALLOC
		ft_putstrn("\nStarting malloc of type ");
	#endif
	ptr = NULL;
	if (size <= 0)
		return NULL;
	size = (size + 15) & ~15;
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
	if (!(heap = (t_heap*)search_free_heap(size, size_type)))
		return (NULL);
	block = create_block(heap, size);
	return ((void*)block + B_META_SIZE);
}