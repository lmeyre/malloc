/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statik.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_heap *g_heap_origin = NULL;
int heapcount = 1; // a virer

//return head (allow modifying inside of it)
t_heap* first_heap()
{
	return (*first_origin());
}

//allow more manipulation like changing the head itself
t_heap **first_origin()
{
	static t_heap *origin = NULL;

	return (&origin);
}