/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:49 by lmeyre            #+#    #+#             */
/*   Updated: 2021/07/15 12:08:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		ft_putnbrn(n / 10);
		ft_putnbrn(n % 10);
	}
	else
	{
		ft_putchar((char)n + '0');
	}
}

void	ft_putnbr(int n)
{
	static int depth = 0;

	depth += 1;

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
	if (depth == 1)
	{
		ft_putchar('\n');
		depth = 0;
	}
	else
		depth -= 1;
}

void	ft_putstr(char const *s)
{
	unsigned int i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
		++i;
	write(1, s, i);
    char c = '\n';
    write(1, &c, 1);
}

void	ft_putstrn(char const *s)
{
	unsigned int i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
		++i;
	write(1, s, i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(s))
		return ;
	ptr = s;
	while (n > 0)
	{
		ptr[i] = '\0';
		++i;
		n--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	pdest = dst;
	psrc = src;
	if (pdest < psrc)
	{
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else if (pdest > psrc)
	{
		while (len--)
		{
			pdest[len] = psrc[len];
		}
	}
	return (dst);
}