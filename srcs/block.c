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

int g_code = 0;//to remove

t_block *try_fusion_block(t_block *block, t_heap *heap)
{
    t_block *prev;
    t_block *next;
    
    prev = get_prev_block(block, heap);
    next = block->next;
    // if(next == NULL)
    //     ft_putstr("Nul next");
    // else
    // {
    //     ft_putstr("Next not null");
    //     if (next->free)
    //         ft_putstr("Acceding next free info");
    // }
    // ft_putstr("Middle");
    if (next != NULL && next->free)
    {
        #ifdef DEBUG_FREE
        //if (debug)
            ft_putstr("Fusioning newly freed block with next one that is also free");
        #endif
        block->next = next->next;
        block->data_size += B_META_SIZE + next->data_size;
    }
    if (prev != NULL && prev->free)
    {
        #ifdef DEBUG_FREE
        //if (debug)
            ft_putstr("Fusioning newly freed block with prev one that is also free");
        #endif
        prev->next = next;
        prev->data_size += B_META_SIZE + block->data_size;
        return prev;
    }
    return block;
}

void init_block(t_block *block, size_t size)
{
    block->free = 0;
    block->data_size = size;
    block->next = NULL;
    block->code = g_code;
    g_code += 1;
    //ft_putstrn("new block, code : ");
    //ft_putnbr(block->code);
}

void    add_block_heap(t_heap *heap, t_block *new_block, t_block* last_block)
{
    if (last_block)
        last_block->next = new_block;
    else
        heap->first_block = new_block;
	heap->free_size -= B_META_SIZE + new_block->data_size;
    // ft_putstrn("new free size = ");
    // ft_putnbr(heap->free_size);
}

t_block	*create_block(t_heap *heap, size_t size)
{
	t_block *last_block;
	t_block *new_block;
    
    #ifdef DEBUG_MALLOC
    //if (debug == 1)
	    ft_putstr("Creating new block");
    #endif
    last_block = heap->first_block;
	while (last_block && last_block->next)
		last_block = last_block->next;
    //If no block in heap, we place it at heap start + heap meta data
    if (last_block == NULL)
        new_block = (t_block*)((void*)heap + H_META_SIZE);
    else//Else we place it at last block pos + block meta data + block size
        new_block = (t_block*)(((void*)last_block + B_META_SIZE) + last_block->data_size);
    
    init_block(new_block, size);
    add_block_heap(heap, new_block, last_block);
    
	//ft_putstr("Finished creating");
    return (new_block);
}

void    *use_free_block(t_block *block, size_t size)
{
    t_block *split;

    // ft_putstr("Splited two block, origin size was : ");
    // ft_putnbr(block->data_size);
    split = (t_block*)((void*)block + B_META_SIZE + size);
    split->next = block->next;
    block->next = split;
    split->data_size = block->data_size - size - B_META_SIZE;
    block->data_size = size;
    split->free = 1;
    block->free = 0;;
    split->code = g_code;
    g_code += 1;
    // ft_putstr("Trying to create a new block of size : ");
    // ft_putnbr(size);
    // ft_putstr("So remaining block size is (+meta)");
    // ft_putnbr(split->data_size);
    // ft_putnbr(B_META_SIZE);

    return ((void*)block + B_META_SIZE);
}
