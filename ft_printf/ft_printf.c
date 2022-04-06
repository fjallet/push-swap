/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:24:21 by fjallet           #+#    #+#             */
/*   Updated: 2022/04/06 12:45:03 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_istype(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	argptr;

	i = 0;
	count = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (ft_istype(str[i + 1]) == 1)
			{
				i++;
				count += ft_swprint(argptr, str[i]);
			}
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(argptr);
	return (count);
}
