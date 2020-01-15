/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:23:17 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:57 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst2;
	const unsigned char *src2;

	if (!(dst) || !(src))
		return (NULL);
	src2 = src;
	dst2 = dst;
	while (n > 0)
	{
		if (*src2 == (unsigned char)c)
		{
			*dst2 = *src2;
			dst2++;
			return (dst2);
		}
		*dst2 = *src2;
		dst2++;
		src2++;
		n--;
	}
	return (NULL);
}
