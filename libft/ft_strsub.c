/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:14:25 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:21:39 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (!(s))
		return (ptr);
	i = 0;
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start];
		i++;
		len--;
		start++;
	}
	return (ptr);
}
