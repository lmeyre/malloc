/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:24:09 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:20:59 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char *psrc;

	if (!dst || !src)
		return (NULL);
	pdest = dst;
	psrc = src;
	while (n > 0)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
		n--;
	}
	return (dst);
}
