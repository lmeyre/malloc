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

void	clear_heap(t_heap *heap)
{
	t_heap *prev;
	t_heap *next;

	next = heap->next;
	prev = get_prev_heap(heap);

	//Ici c'est plsu simple que les blocks, on a pas a relier les espace vide, ce sont des heaps et pas des  block au sein d'une heap
	if (prev != NULL)
		prev->next = next;
	if (heap == first_heap())
	{
		t_heap **ref_first = first_origin();
		*ref_first = next;
	}
	munmap(heap, heap->total_size);
}

//Si on free le premier block, et que yen a apres, on veut pas le mettre a null, on met juste la fin a null
//si c'est le premier et le dernier, on peut le mettre a null
void	clear_heap_end(t_heap *heap, t_block *block, int debug)
{
	t_block *prev;

	if (!block->free)
		ft_putstr("WTFFFFF ??????????????????????");
	if (block->next == NULL)// si on est sur le dernier block on peut le virer     a voir si on est pas dessus
	{
		if (debug == 1)
			ft_putstr("Clearing heap end");
		prev = get_prev_block(block, heap);
		heap->free_size += B_META_SIZE + block->data_size;
		if (prev != NULL)
			prev->next = NULL;
		else if (block == heap->first_block)
			heap->first_block = NULL;//We remove the first and last block
	}
	// faut faire gaffe la c'est chelou car du coup le "start" se situe plus juste au debut de la heap mais apres la taille du block qu'on a virer  ~ problem ? on le fait pas du coup
	// else if (block == heap->first_block)
	// 	heap->first_block = block->next;
}

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

t_heap	*create_heap(size_t size, t_data_type type)
{
	t_heap *new_heap;

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

	//ft_putstr("No avalaible heap, creating new one\n");
	heap_size = get_heap_size(type, size);
	if (heap_size > check_limit())
		return (NULL);
	if ((heap = create_heap(heap_size, type)) == NULL)
		return NULL;
	
	return heap;
}
