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

void    empty_block(t_heap *heap, t_block *block, void *ptr)
{
	//bzero the ptr and not the block, so we only bzero what was stocked inside and now the meta
	ft_bzero(ptr, block->data_size);
	block->free = 1
	//if the previous or next is also free, we make a big free block from 2
	try_fusion_block(block, heap);
}

void    free(void* ptr)
{
    t_heap *origin;
    t_heap *target_heap;
    t_block *target_block;

    if (ptr == NULL)
        return ;
    origin = first_heap();
    if (origin == NULL)
        return ;
    find_block(ptr, origin, &target_heap, &target_block);
    if (target_block != NULL)
	{
        empty_block(target_heap, target_block, ptr);
		clear_heap_end(heap, block);
		if (heap->first_block == NULL)
			clear_heap(heap);
	}
    else
        ft_putstr("Didnt found the malloc to free ;c");
}