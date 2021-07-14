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
		block = (t_block *)((void*)current_heap + H_META_SIZE);
		while (block)
		{
			if (((void*)(block + B_META_SIZE)) == ptr)
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
        
    }
    else
        ft_putstr("Didnt found the malloc to free ;c");
}