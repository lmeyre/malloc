/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_chartab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:12:54 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/01 18:01:02 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_create_chartab(int size, int sizelittle)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char*)
		* ((unsigned long)(size + 1)))))
		return (NULL);
	while (size > i)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char)
			* ((unsigned long)(sizelittle + 1)))))
			return (NULL);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
