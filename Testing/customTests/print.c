/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:47:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/31 18:29:16 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./test.h"

void show_heap_list()
{
    int i = 0;
    t_heap *heap = first_heap();

    printf("DEBUG: heap list\nCareful, this use printf and may trigger a malloc !\n");

    while (heap) 
    {
        int bCount = 0;
        t_block *bl = heap->first_block;;
        while (bl)
        {
            bCount += 1;
            bl = bl->next;
        }
        printf(
            "%d. heap %p, next: %p (total size: %zu, free_space: %zu), it has %d blocks\n",
            i,
            heap,
            heap->next,
            heap->total_size,
            heap->free_size,
            bCount);
        heap = heap->next;
        i++;
    }
}
