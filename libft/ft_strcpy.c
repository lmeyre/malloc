/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:25:42 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:21:24 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	i = 0;
	while (*src)
	{
		dest[i++] = *src++;
	}
	dest[i] = '\0';
	return (dest);
}
