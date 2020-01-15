/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_unsignedlong.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 21:40:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/27 21:40:22 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned long long		ft_atoi_unsignedlong(const char *str)
{
	int					i;
	unsigned long long	k;

	if (!(str))
		return (0);
	k = 0;
	i = 0;
	while (str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (0);
	str[i] == '+' ? ++i : 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + (unsigned long long)(str[i] - '0');
		i++;
	}
	return (k);
}
