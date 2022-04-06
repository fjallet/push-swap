/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:12:05 by fjallet           #+#    #+#             */
/*   Updated: 2022/04/06 12:46:06 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg1(va_list argptr, char c)
{
	int		count;
	char	*str;
	void	*lu;

	count = 0;
	if (c == 's')
	{
		str = va_arg(argptr, char *);
		count = ft_putstr(str);
	}
	if (c == 'p')
	{
		lu = va_arg(argptr, void *);
		count += ft_putstr("0x");
		count += ft_putnbrbasel((long long unsigned int)lu, "0123456789abcdef");
	}
	return (count);
}

int	ft_printarg2(va_list argptr, char c)
{
	int				count;
	int				entier;

	count = 0;
	if (c == 'c')
	{
		entier = va_arg(argptr, int);
		count = ft_putchar(entier);
	}
	if (c == 'd' || c == 'i')
	{
		entier = va_arg(argptr, int);
		ft_putnbr(entier, &count);
	}
	return (count);
}

int	ft_printarg3(va_list argptr, char c)
{
	int				count;
	unsigned int	u;

	count = 0;
	if (c == 'u')
	{
		u = va_arg(argptr, unsigned int);
		ft_putnbru(u, &count);
	}
	if (c == 'x')
	{
		u = va_arg(argptr, unsigned int);
		count = ft_putnbrbase(u, "0123456789abcdef");
	}
	if (c == 'X')
	{
		u = va_arg(argptr, unsigned int);
		count = ft_putnbrbase(u, "0123456789ABCDEF");
	}
	return (count);
}

int	ft_swprint(va_list argptr, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar('%');
	if (c == 's' || c == 'p')
		count = ft_printarg1(argptr, c);
	if (c == 'd' || c == 'i' || c == 'c')
		count = ft_printarg2(argptr, c);
	if (c == 'u' || c == 'x' || c == 'X')
		count = ft_printarg3(argptr, c);
	return (count);
}
