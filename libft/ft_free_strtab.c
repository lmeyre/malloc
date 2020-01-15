/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:07:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:40 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_free_strtab(char ***tab)
{
	int i;

	if (!*tab || !tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	free(*tab);
	tab = NULL;
}
