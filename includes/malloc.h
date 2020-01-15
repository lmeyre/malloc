/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:07:46 by lmeyre            #+#    #+#             */
/*   Updated: 2020/01/15 14:07:50 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MALLOC_H

# define MALLOC_H
# include <stdlib.h>
# include <sys/mman.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_heap
{
    struct s_heap* prev;
    struct s_heap* next;
    //t_heap_group    group;
    size_t          total_size;
    size_t          free_size;
    size_t          block_count;
} t_heap;

typedef struct s_block
{
    struct s_block* prev;
    struct s_block* next;
    size_t          data_size;
    int             freed;
} t_block;

//# define HEAP_SHIFT(start) ((void *)start + sizeof(t_heap))
//# define BLOCK_SHIFT(start) ((void *)start + sizeof(t_block))


# define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
# define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)

#endif