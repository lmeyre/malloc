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

void*realloc(void *ptr, size_t size)
{
    t_block *block;
    t_heap  *heap;
    void    *ret_ptr;
    if (ptr == NULL)
        return (malloc(size));
    else if (size == 0)
    {
        free(ptr);
        return (NULL);
    }

    find_block(ptr, heap, block);
    if (!block)
        return (NULL);
    if (size == block->data_size)
        return (ptr);
    ret_ptr = malloc(size);
    if (size > block->data_size)
        ft_memmove(ret_ptr, ptr, block->data_size);
    else
        ft_memmove(ret_ptr, ptr, size;
    free(ptr);
    return (ret_ptr);
}