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

//voir si on l'enleve ca fait un peu cramer
static rlim_t	check_limit(void)
{
	struct rlimit limit;

	if (getrlimit(RLIMIT_DATA, &limit) < 0)
		return (-1);
	return (limit.rlim_max);
}

void	prepare_heap(t_heap* heap, size_t size, t_data_type type)
{
	t_heap* heap_chain;
	heap->total_size = size;
	heap->type = type;
	heap->free_size = heap->total_size;
	//pour verif que la transition de pointeur se fait bien
	// heap->count = heapcount;
	// heapcount += 1;
	// ft_putstr("Before pointeur, origin, et curr : ");
	// ft_putnbr(heap_origin->count);
	// ft_putnbr(heap->count);
	// heap->next = heap_origin;
	// //A revoir comment on assigne ca avec les pointeurs	
	// heap_origin = heap;


	// ft_putstr("After pointeur, origin, et origin->next : ");
	// ft_putnbr(heap_origin->count);
	// ft_putnbr(heap_origin->next->count);

	heap->blocks = NULL;
	
	//extern t_heap *g_heap_origin;
	//heap_chain = g_heap_origin;
	heap_chain = first_heap();
	
	
	while (heap_chain && heap_chain->next)
		heap_chain = heap_chain->next;

	if (heap_chain)
		heap_chain->next = heap;
	else
	{
		//heap_origin = heap;
		t_heap **ref_first = first_origin();
		*ref_first = heap;
		//Attention ici verifyier que ca a modifier la valeur de la static, (du pointer). si non il faut une etoile de plus
		//Ca a lair bon
		// printf("%p\n", new_heap);
		// printf("%p\n", first_heap());
		// printf("Here\n");
	}
}

t_heap	*create_heap(size_t size, t_data_type type)
{
	t_heap *new_heap;
	
		//addr = mmap(NULL, length + offset - pa_offset, PROT_READ,
                //MAP_PRIVATE, fd, pa_offset);
	//if ((new_heap =mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0)) == NULL)//si soucis essayer SHARED
	//Pnser quer pour les tiny small on verify la place a chaque fois mais le large il faut malloc pour le malloc + p meta et b meta
	if ((new_heap = (t_heap*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return NULL;
	ft_bzero(new_heap, sizeof(new_heap));
	
	prepare_heap(new_heap, size, type);
	return new_heap;
}

size_t get_heap_size(t_data_type type, size_t size)
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

//When we create a new heap, we must also create a block for the current malloc and return its pointer
t_heap	*new_heap(size_t size, t_data_type type)
{
	t_heap *heap = NULL;
	size_t heap_size;

	ft_putstr("No avalaible heap, creating new one\n");
	heap_size = get_heap_size(type, size);
	if (heap_size > check_limit())
		return (NULL);
	if ((heap = create_heap(heap_size, type)) == NULL)
		return NULL;
	
	return heap;
	// t_block *block = create_block(heap, size);
	// // printf("end of heap, first block = %p\n", first_heap()->blocks);
	// // printf("is it free  %d\n", first_heap()->blocks->freed);
	// return (block);
}
