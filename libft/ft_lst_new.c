/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 09:40:12 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:53 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_new(size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content_size == 0)
		ptr->content = NULL;
	else if (!(ptr->content = ft_memalloc(content_size)))
		return (NULL);
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
