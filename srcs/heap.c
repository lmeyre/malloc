/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			clear_heap(t_heap *heap)
{
	t_heap *prev;

	if (heap == first_heap())
	{
		t_heap **ref_first = first_origin();
		*ref_first = heap->next;
	}
	else
	{
		prev = get_prev_heap(heap);
		if (prev != NULL)
			prev->next = heap->next;
	}
	#ifdef DEBUG_FREE
		ft_putstrn("Releasing memory amount = ");
		ft_putnbr(heap->total_size);
	#endif
	munmap((void*)heap, heap->total_size);
}

void			clear_heap_end(t_heap *heap, t_block *block)
{
	t_block *prev;

	if (block->next == NULL)
	{
		#ifdef DEBUG_FREE
			ft_putstr("Clearing heap end");
		#endif
		prev = get_prev_block(block, heap);
		heap->free_size += B_META_SIZE + block->data_size;
		if (prev != NULL)
			prev->next = NULL;
		else if (block == heap->first_block)
			heap->first_block = NULL;
	}
}

static rlim_t	test_limit(void)
{
	struct rlimit limit;

	if (getrlimit(RLIMIT_DATA, &limit) < 0)
		return (-1);
	return (limit.rlim_max);
}

void			prepare_heap(t_heap* heap, size_t size, t_data_type type)
{
	t_heap* heap_chain;

	heap->total_size = size;
	heap->type = type;
	heap->free_size = heap->total_size;
	heap->first_block = NULL;
	heap_chain = first_heap();
	while (heap_chain && heap_chain->next)
		heap_chain = heap_chain->next;
	if (heap_chain)
		heap_chain->next = heap;
	else
	{
		t_heap **ref_first = first_origin();
		*ref_first = heap;
	}
}

t_heap			*create_heap(size_t size, t_data_type type)
{
	t_heap *new_heap;

	#ifdef DEBUG_MALLOC
		ft_putstrn("Allocating memory for heap = ");
		ft_putnbr(size);
	#endif
	if ((new_heap = (t_heap*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return NULL;
	ft_bzero(new_heap, sizeof(new_heap));
	prepare_heap(new_heap, size, type);
	return new_heap;
}

size_t			get_heap_size(t_data_type type, size_t size)
{
	size_t heap_size;

	if (type == TINY)
		heap_size = TINY_HEAP_ALLOCATION_SIZE;
	else if (type == SMALL)
		heap_size = SMALL_HEAP_ALLOCATION_SIZE;
	else
		heap_size = size + H_META_SIZE + B_META_SIZE;
	return heap_size;
}

t_heap			*new_heap(size_t size, t_data_type type)
{
	t_heap *heap = NULL;
	size_t heap_size;

	heap_size = get_heap_size(type, size);
	ft_putnbr(test_limit());
	if (heap_size > test_limit())
	{
		#ifdef DEBUG_MALLOC
		ft_putstr("Limit reached, canceling malloc");
		#endif
		return (NULL);
	}
	if ((heap = create_heap(heap_size, type)) == NULL)
		return NULL;
	return heap;
}
