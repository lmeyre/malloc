/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhexa_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:30:25 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 16:31:07 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	adding(char c)
{
	char	*converter;
	char	*converter_bis;
	int		i;

	converter = "0123456789ABCDEF";
	converter_bis = "0123456789abcdef";
	i = 0;
	while (converter[i])
	{
		if (converter[i] == c)
			return (i);
		++i;
	}
	i = 0;
	while (converter_bis[i])
	{
		if (converter_bis[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int			ft_strhexa_int(char *str)
{
	int i;
	int j;
	int value;

	value = 0;
	i = 0;
	j = 0;
	while (str[i])
		++i;
	--i;
	while (i >= 0)
	{
		value += adding(str[i]) * ft_power(16, j);
		++j;
		--i;
	}
	return (value);
}
