/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:26:49 by fjallet           #+#    #+#             */
/*   Updated: 2022/04/06 12:45:00 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counthexa(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr > 15)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	ft_putnbrbase(unsigned int nbr, char *b)
{
	if (nbr > 15)
	{
		ft_putnbrbase(nbr / 16, b);
		ft_putchar(b[nbr % 16]);
	}
	else
		ft_putchar(b[nbr % 16]);
	return (ft_counthexa(nbr));
}

int	ft_counthexal(long long unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr > 15)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	ft_putnbrbasel(long long unsigned int nbr, char *b)
{
	if (nbr > 15)
	{
		ft_putnbrbasel(nbr / 16, b);
		ft_putchar(b[nbr % 16]);
	}
	else
		ft_putchar(b[nbr % 16]);
	return (ft_counthexal(nbr));
}
