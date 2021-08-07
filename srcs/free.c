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

void	find_block(void *ptr, t_heap *current_heap, t_heap **target_heap, t_block **target_block)
{
	t_block *block;

	block = NULL;
	while (current_heap)
	{
		//block = (t_block *)((void*)current_heap + H_META_SIZE);
		block = current_heap->first_block;
		while (block)
		{
            //on verifie pas le block, mais le block apres meta, car c'est ce qu'on a rendu via malloc
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

t_block    *empty_block(t_heap *heap, t_block *block, void *ptr, int debug)
{
	//bzero the ptr and not the block, so we only bzero what was stocked inside and not the meta
	ft_bzero(ptr, block->data_size);
	block->free = 1;
	//if the previous or next is also free, we make a big free block from 2
	return (try_fusion_block(block, heap, debug));
}

void    free(void* ptr)
{
    t_heap *origin;
    t_heap *target_heap;
    t_block *target_block;
	static int debug = 0;

	if (debug == 1)
		ft_putstr("\nStarting free");
    if (ptr == NULL)
        return ;
    origin = first_heap();
    if (origin == NULL)
        return ;
	if (debug == 1)
		ft_putstr("Looking for the pointer in the heaps and blocks");
    find_block(ptr, origin, &target_heap, &target_block);
    if (target_block != NULL)
	{
		if (debug == 1)
			ft_putstr("Found it, trying to fusion free blocks");
        target_block = empty_block(target_heap, target_block, ptr, debug);
		clear_heap_end(target_heap, target_block, debug);
		if (target_heap->first_block == NULL)
		{
			if (debug == 1)
				ft_putstr("Heap now empty, removing it");
			clear_heap(target_heap);
		}
		if (debug == 1)
			ft_putstr("Done freeing");
	}
    else if (debug == 1)
        ft_putstr("Found no block block corresponding to the malloc we are trying to free");
}