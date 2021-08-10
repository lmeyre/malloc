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

void    dump_heap(t_heap *heap)
{
    size_t len;
    size_t i;
    int j;

    i = 0;
    len = heap->total_size + H_META_SIZE;
    ft_putnbr(len);
    ft_putnbr(H_META_SIZE);
    ft_putnbr(heap->total_size);
    while(i < len)
    {
        ft_itoa_base_str(((size_t)(heap + i)), 16, 0, 1);
        ft_putstrn(" ~ ");
        j = 0;
        while (j < 16)
        {
            ft_itoa_base_str((unsigned char)(heap + i), 16, 2, 0);
            ft_putchar(' ');
            i++;
            j++;
        }
        ft_putchar('\n');
    }
}

size_t  scan_blocks(t_heap *heap)
{
    void    *block_start;
    void    *block_end;
    t_block *curr;
    size_t  size;
    int     len;

    curr = heap->first_block;
    size = 0;
    while(curr)
    {
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
            ft_putnbrn(curr->data_size);
            ft_putstr(" octets");
        }
        curr = curr->next;
    }
    return size;
}

size_t  process_heap(t_heap *heap, int hexa)
{
    size_t size;
    int     len;

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
    if (hexa == 0)
        size = scan_blocks(heap);
    else
    {
        size = 0;
        dump_heap(heap);
    }

    return size;
}

t_heap  *get_first_heap_memory(t_heap *last_heap)
{
    t_heap  *loop;
    t_heap  *best;

    best = NULL;
    loop = first_heap();
    while(loop)
    {
        if (last_heap == NULL)
        {
            if (best == NULL)
                best = loop;
            else if ((uintptr_t)loop < (uintptr_t)best)
                best = loop;
        }
        else
        {
            if (best == NULL && (uintptr_t)loop > (uintptr_t)last_heap)
                best = loop;
            else if ((uintptr_t)loop < (uintptr_t)best && (uintptr_t)loop > (uintptr_t)last_heap)
                best = loop;
        }
        loop = loop->next;
    }
    return best;
}

void    show_alloc_mem(void)
{
    t_heap  *heap;
    size_t size;

    heap = first_heap();
    if (heap == NULL)
    {
        ft_putstr("Total : 0 octets");
        return ;
    }
    size = 0;
    ft_putstr("\n");
    heap = NULL;
    while((heap = get_first_heap_memory(heap)) != NULL)
    {
        size += process_heap(heap, 0);
    }
    ft_putstrn("Total : ");
    ft_putnbrn(size);
    ft_putstr(" octets");
}

void    show_alloc_mem_hex(void)
{
    t_heap  *heap;

    heap = first_heap();
    if (heap == NULL)
    {
        return ;
    }
    ft_putstr("\n");
    heap = NULL;
    while((heap = get_first_heap_memory(heap)) != NULL)
    {
        process_heap(heap, 1);
        ft_putchar('\n');
    }
}