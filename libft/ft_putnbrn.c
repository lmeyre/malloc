/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:46:51 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 15:21:13 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbrn(int n)
{
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar('-');
		ft_putchar('2');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar((char)n + '0');
	}
	ft_putchar('\n');
}
