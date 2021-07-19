/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t    scan_blocks(t_heap *heap)
{
    void    *block_start;
    void    *block_end;
    t_block *curr;
    size_t  size;
    int     len;

    curr = heap->first_block;
    size = 0;
    //For blocks, we do as the exemple in subject and print avoiding the meta
    //for heap it doesnt really matter since heap arent linked close one another
    
    while(curr)
    {
        ft_putstrn("One block, code : ");
        ft_putnbr(curr->code);
        if (!(curr->free))
        {
            block_start = ((void*)curr + B_META_SIZE);
            block_end = block_start + curr->data_size;
            size += curr->data_size;
            
            len = get_len_conv((uintptr_t)block_start, 16);
            print_memory((uintptr_t)block_start, 16, "0123456789ABCDEF", len);
            ft_putstrn(" - ");
            len = get_len_conv((uintptr_t)block_end, 16);
            print_memory((uintptr_t)block_end, 16, "0123456789ABCDEF", len);
            ft_putstrn(" : ");
            ft_putnbrn(size);
            ft_putstr(" octets");
        }
        curr = curr->next;
    }
    return size;
}

void	show_alloc_mem(void)
{
    t_heap  *heap;
    int     len;
    size_t size;

    heap = first_heap();
    size = 0;
    ft_putstr("\n\n");
    while(heap)
    {
	    len = get_len_conv((uintptr_t)heap, 16);
        if (heap->type == TINY)
		    ft_putstrn("TINY");
        else if (heap->type == SMALL)
            ft_putstrn("SMALL");
        else
            ft_putstrn("LARGE");
        ft_putstrn(" : ");
        print_memory((uintptr_t)heap, 16, "0123456789ABCDEF", len);
        ft_putchar('\n');
        size += scan_blocks(heap);
        heap = heap->next;
    }
    ft_putstrn("Total : ");
    ft_putnbrn(size);
    ft_putstr(" octets");
}