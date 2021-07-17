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

void try_fusion_block(t_block *block, t_heap *heap)
{
    t_block prev;
    t_block next;
    
    prev = get_prev_block(block, heap);
    next = block->next;
    
    if (next != NULL && next->free)
    {
        block->next = next->next;
        block->data_size += B_META_SIZE + next->data_size;
    }
    if (prev != NULL && prev->free)
    {
        prev->next = next;
        prev->data_size += B_META_SIZE + block->data_size;
    }
}

void init_block(t_block *block, size_t size)
{
    block->freed = 0;
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

t_block	*create_block(t_heap *heap, size_t size)
{
	t_block *last_block;
	t_block *new_block;
    
    
	ft_putstr("Creating new block");
    last_block = heap->first_block;
	while (last_block && last_block->next)
		last_block = last_block->next;
    //If no block in heap, we place it at heap start + heap meta data
    if (last_block == NULL)
        new_block = (t_block*)((void*)heap + H_META_SIZE);
    else//Else we place it at last block pos + block meta data + block size
        new_block = (t_block*)(((void*)last_block + B_META_SIZE) + last_block->data_size);
    
    add_block_heap(heap, new_block, last_block);
    init_block(new_block, size);

    // printf("curr block %p and space addr = %p\n", new_block, addr);
    // printf("curr heap = %p and first page heap = %p\n", heap, first_heap());
    // printf("first block heap adress = %p and curr block = %p and first block from curr heap = %p\n", first_heap()->blocks, new_block, heap->blocks);
	//printf("is it free  %d\n", first_heap()->blocks->freed);

    //Pour return sur la position de la data, et eviter le meta size qui est juste necessaire pour la memoire et le pointeur
    //Tester sans ? jteraz fait ca, donc a priori good
    
	ft_putstr("Finished creating");
    return (new_block);
}

void    *use_free_block(t_block *block, size_t size)
{
    t_block *split;

    ft_putstr("Splited two block, origin size was : ");
    ft_putnbr(block->data_size)
    split = (t_block*)((void*)block + B_META_SIZE + size);
    split->next = block->next;
    block->next = split;
    split->data_size = block->data_size - size - B_META_SIZE;
    block->data_size = size;
    split->free = 1;
    block->free = 0;;
    ft_putstr("Trying to create a new block of size : ");
    ft_putnbr(size);
    ft_putstr("So remaining block size is (+meta)");
    ft_putnbr(split->data_size);
    ft_putnbr(B_META_SIZE);

    return ((void*)block + B_META_SIZE);
}
