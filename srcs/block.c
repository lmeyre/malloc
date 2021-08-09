/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block *try_fusion_block(t_block *block, t_heap *heap)
{
    t_block *prev;
    t_block *next;
    
    prev = get_prev_block(block, heap);
    next = block->next;
    if (next != NULL && next->free)
    {
        #ifdef DEBUG_FREE
            ft_putstr("Fusioning newly freed block with next one that is also free");
        #endif
        block->next = next->next;
        block->data_size += B_META_SIZE + next->data_size;
    }
    if (prev != NULL && prev->free)
    {
        #ifdef DEBUG_FREE
            ft_putstr("Fusioning newly freed block with prev one that is also free");
        #endif
        prev->next = next;
        prev->data_size += B_META_SIZE + block->data_size;
        return prev;
    }
    return block;
}

void    init_block(t_block *block, size_t size)
{
    block->free = 0;
    block->data_size = size;
    block->next = NULL;
}

void    add_block_heap(t_heap *heap, t_block *new_block, t_block* last_block)
{
    if (last_block)
        last_block->next = new_block;
    else
        heap->first_block = new_block;
	heap->free_size -= B_META_SIZE + new_block->data_size;
}

t_block *create_block(t_heap *heap, size_t size)
{
	t_block *last_block;
	t_block *new_block;
    
    #ifdef DEBUG_MALLOC
	    ft_putstr("Creating new block");
    #endif
    last_block = heap->first_block;
	while (last_block && last_block->next)
		last_block = last_block->next;
    if (last_block == NULL)
        new_block = (t_block*)((void*)heap + H_META_SIZE);
    else
        new_block = (t_block*)(((void*)last_block + B_META_SIZE) + last_block->data_size);
    init_block(new_block, size);
    add_block_heap(heap, new_block, last_block);
    return (new_block);
}

void    *use_free_block(t_block *block, size_t size)
{
    t_block *split;

    split = (t_block*)((void*)block + B_META_SIZE + size);
    split->next = block->next;
    block->next = split;
    split->data_size = block->data_size - size - B_META_SIZE;
    block->data_size = size;
    split->free = 1;
    block->free = 0;;
    return ((void*)block + B_META_SIZE);
}
