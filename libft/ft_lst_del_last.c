/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:27:44 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/03 19:26:13 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lst_del_last(t_list **lst)
{
	t_list	*start;

	if (!lst || !*lst)
		return ;
	start = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->prev->next = NULL;
	if ((*lst)->content)
		free((*lst)->content);
	(*lst)->content = NULL;
	free(*lst);
	*lst = NULL;
	*lst = start;
}
