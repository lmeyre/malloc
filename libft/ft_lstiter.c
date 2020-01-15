/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:57:17 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:56 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!(f) || !(lst))
		return ;
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
