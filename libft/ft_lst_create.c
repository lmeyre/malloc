/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:59:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:49 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_create_lst(int size, int content_size)
{
	t_list	*start;
	t_list	*curr;
	t_list	*prev;

	if (!(start = ft_lst_new((size_t)content_size)))
		return (NULL);
	curr = start;
	prev = NULL;
	while (size > 1)
	{
		if (!(curr->next = ft_lst_new((size_t)content_size)))
			return (NULL);
		curr->prev = prev;
		prev = curr;
		curr = curr->next;
		--size;
	}
	curr->prev = prev;
	return (start);
}
