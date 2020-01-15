/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_advance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:00:18 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/03 16:00:34 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_lst_advance(t_list **head, int advance)
{
	if (!head || !*head)
		return (0);
	while (advance > 1)
	{
		if ((*head)->next == NULL)
			return (0);
		*head = (*head)->next;
		--advance;
	}
	return (1);
}
