/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:22:22 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:51 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lst_del_one(t_list **head, int position)
{
	t_list	*over;
	t_list	*curr;

	over = NULL;
	if (!head || !(*head))
		return ;
	curr = *head;
	if (!(ft_lst_advance(&curr, position)))
		return ;
	(curr->prev) ? (curr->prev)->next = curr->next : 0;
	(curr->next) ? (curr->next)->prev = curr->prev : 0;
	if (curr->prev)
		over = curr->prev;
	else if (curr->next)
		over = curr->next;
	ft_lst_cnttdel(&curr->content);
	free(curr);
	curr = NULL;
	if (over != NULL)
		while (over->prev)
			over = over->prev;
	*head = over;
}
