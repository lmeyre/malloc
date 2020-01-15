/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:47:19 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:21:26 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup_free(const char *s1, char **out)
{
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	if (!(s2 = (char*)ft_memalloc(sizeof(char) * ((unsigned int)(1 + i)))))
		return (0);
	s2[i] = '\0';
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	if (*out)
		ft_strdel(out);
	return (s2);
}
