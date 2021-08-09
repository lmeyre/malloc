/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		ready_to_clear(t_heap *heap)
{
	t_heap	*first;

	first = first_heap();
	while(first)
	{
		if (first->type == heap->type && first != heap)
		{
			return 1;
		}
		first = first->next;
	}
	return 0;
}

void	find_block(void *ptr, t_heap *current_heap, t_heap **target_heap, t_block **target_block)
{
	t_block *block;

	block = NULL;
	while (current_heap)
	{
		block = current_heap->first_block;
		while (block)
		{
			if (((void*)block + B_META_SIZE) == ptr)
			{
				*target_block = block;
				*target_heap = current_heap;
				return ;
			}
			block = block->next;
		}
		current_heap = current_heap->next;
	}
	*target_block = NULL;
	*target_heap = NULL;
}

t_block	*empty_block(t_heap *heap, t_block *block)
{
	//bzero the ptr and not the block, so we only bzero what was stocked inside and not the meta -> we wish to do it, but for unknow reason it greatly inecrease page reclaim count..
	//ft_bzero(ptr, block->data_size);
	block->free = 1;
	return (try_fusion_block(block, heap));
}

void	free(void* ptr)
{
    t_heap *origin;
    t_heap *target_heap;
    t_block *target_block;

	#ifdef DEBUG_FREE
		ft_putstr("\nStarting free");
	#endif
    if (ptr == NULL)
        return ;
    origin = first_heap();
    if (origin == NULL)
        return ;
	#ifdef DEBUG_FREE
		ft_putstr("Looking for the pointer in the heaps and blocks");
	#endif
    find_block(ptr, origin, &target_heap, &target_block);
    if (target_block != NULL)
	{
		#ifdef DEBUG_FREE
			ft_putstr("Found it, trying to fusion free blocks");
		#endif
        target_block = empty_block(target_heap, target_block);
		clear_heap_end(target_heap, target_block);
		if (target_heap->first_block == NULL)
		{
			#ifdef DEBUG_FREE
				ft_putstr("Heap now empty, preparing to remove it if conditions are met");
			#endif
			if (ready_to_clear(target_heap) == 1)
				clear_heap(target_heap);
		}
		#ifdef DEBUG_FREE
			ft_putstr("Done freeing");
		#endif
	}
    else 
	{
		#ifdef DEBUG_FREE
        	ft_putstr("Found no block block corresponding to the malloc we are trying to free");
		#endif
	}
}