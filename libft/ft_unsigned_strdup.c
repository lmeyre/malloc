/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_strdup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:49:46 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:21:45 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned char	*ft_unsigned_strdup(char *s1)
{
	int				i;
	unsigned char	*s2;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	if (!(s2 = (unsigned char*)malloc(sizeof(unsigned char)
			* ((unsigned long)(1 + i)))))
		return (0);
	s2[i] = '\0';
	--i;
	while (i >= 0)
	{
		s2[i] = (unsigned char)s1[i];
		i--;
	}
	return (s2);
}
