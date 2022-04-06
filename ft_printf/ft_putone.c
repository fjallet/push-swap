/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:59:40 by fjallet           #+#    #+#             */
/*   Updated: 2022/04/06 12:45:05 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar(n % 10 + 48);
	}
	else
		*count += ft_putchar(n % 10 + 48);
	return ;
}

void	ft_putnbru(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbru(n / 10, count);
		*count += ft_putchar(n % 10 + 48);
	}
	else
		*count += ft_putchar(n % 10 + 48);
	return ;
}
