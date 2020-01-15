/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:28:31 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:52 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_int_copy(t_list *lst)
{
	t_list *copy_head;
	t_list *tmp_main;
	t_list *tmp_copy;

	if (!lst)
		return (NULL);
	if (!(copy_head = ft_lst_new(sizeof(lst->content))))
		return (NULL);
	*((int*)(copy_head->content)) = *((int*)(lst->content));
	tmp_copy = copy_head;
	tmp_main = lst->next;
	while (tmp_main)
	{
		if (!(tmp_copy->next = ft_lst_new(sizeof(tmp_main->content))))
			return (NULL);
		tmp_copy->next->prev = tmp_copy;
		tmp_copy = tmp_copy->next;
		*(int*)tmp_copy->content = *(int*)tmp_main->content;
		tmp_main = tmp_main->next;
	}
	return (copy_head);
}
