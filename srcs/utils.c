/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_data_type return_type(size_t size)
{
    t_data_type type;
    
    if (size <= (size_t)TINY_BLOCK_SIZE)
	    type = TINY;
    else if (size <= (size_t)SMALL_BLOCK_SIZE)
    {
	    type = SMALL;
    }
    else
        type = LARGE;
    return type;
}

t_block     *get_prev_block(t_block *block, t_heap *heap)
{
    t_block *first ;
    
    first = heap->first_block;
    while (first && first->next)
    {
        if(first->next == block)
        {
            return first;
        }
        first = first->next;
    }
    return NULL;
}

t_heap      *get_prev_heap(t_heap *heap)
{
    t_heap *first ;
    
    first = first_heap();
    while (first && first->next)
    {
        if(first->next == heap)
            return first;
        first = first->next;
    }
    return NULL;
}

int         get_len_conv(uintptr_t value, int base)
{
	int len;

	len = 0;
	while (value / base > 0)
	{
	    value /= base;
	    len++;
	}
	return (len + 1);
}

void        print_memory(uintptr_t value, int base, char *base_str, int len)
{
	char	str[len];

	str[len] = '\0';
	len--;
	while (len >= 0)
	{
        str[len] = base_str[value % base];
        value /= base;
        len--;
	}
    if (base == 16)
    ft_putstrn("0x");
    ft_putstrn(str);
}