/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:20:59 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:21:41 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim_c(char const *s, char c)
{
	int		start;
	int		end;
	int		k;
	char	*ptr;

	if (!(s))
		return (NULL);
	start = 0;
	while (s[start] == c)
	{
		start++;
	}
	k = start;
	end = start;
	while (s[k])
	{
		if (s[k] != c)
			end = k;
		k++;
	}
	ptr = ft_strsub(s, (unsigned int)start, (size_t)(end - start + 1));
	return (ptr);
}
