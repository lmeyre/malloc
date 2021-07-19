/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:47:16 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/22 12:17:27 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./test.h"
#include <stdio.h>
#include <unistd.h>

static void test_malloc_null()
{
    void *t = malloc(0);
    if (t)
        printf("malloc(0) should return NULL\n");
    free(t);
}

static void test_malloc_one()
{
    char *t = (char *)malloc(1);
    if (!t) {
        printf("malloc(1) should return ptr\n");
        return;
    }
    t[0] = 0xFF;
    t[1] = 0xFF;
    t[2] = 0xFF;
    t[3] = 0xFF;
    //~~~ removed by us show_alloc_mem_hex();

    t[0] = 0;
    free(t);
}

static void test_malloc_getpagesize()
{
    void *t = malloc(getpagesize());
    free(t);
}

// !!!!!!!!!!!!!!!!
// TODO SHOULD FILL 3 sizes
// CHECK To free all, see if the TINY and SMALL stay
static void test_malloc_limits()
{
    void	*t	    = malloc(1);
    show_heap_list();
    void	*t0	    = malloc(TINY_BLOCK_SIZE);
    void	*t00	= malloc(TINY_BLOCK_SIZE);
    void	*t000	= malloc(TINY_BLOCK_SIZE);
    show_alloc_mem();
    void	*t1	    = malloc(SMALL_BLOCK_SIZE);
    void	*t2	    = malloc(SMALL_BLOCK_SIZE + 1);
    show_heap_list();

    //printf("printf t0 (block apres meta) : %p\n", t0);

    return;

    // Should print mallocs in all categories (TINY, SMALL, LARGE)
    // show_alloc_mem();
    // show_alloc_mem_hex();
    // show_heap_list();

    // ft_putstr("t");
    // free(t0);
    // t0 = malloc(TINY_BLOCK_SIZE - sizeof(t_block));
    // // show_alloc_mem();
    // free(t0);
    // ft_putstr("t00");
    // free(t00);
    // ft_putstr("t000");
    // free(t000);
    // ft_putstr("t1");
    // free(t1);
    // ft_putstr("t2");
    // free(t2);
}

static void test_malloc_free_size()
{
    void *t = malloc(SMALL_BLOCK_SIZE + 1);

    // heap should have 0 free_space
    // show_heap_list();

    free(t);
}

void run_test_malloc(void)
{
    // test_malloc_null();
    // test_malloc_one();
    // ft_putstr("testing page size");
    // test_malloc_getpagesize();
    ft_putstr("Testing limit");
    test_malloc_limits();
    ft_putstr("testing free size");
    test_malloc_free_size();
    ft_putstr("Done");

    // show_alloc_mem();
    // show_heap_list();
}


    // ft_putstr("data_size: ");
    // ft_itoa_base(block->data_size, 10, 0, FALSE);
    // ft_putstr(" sup to : ");
    // ft_itoa_base(size + sizeof(t_block), 10, 0, FALSE);
    // ft_putstr("\n");
