/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:25:49 by fjallet           #+#    #+#             */
/*   Updated: 2022/04/06 12:45:02 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//ft_printf.c
int		ft_printf(const char *str, ...);
void	ft_incarg(va_list argptr, char c);
int		ft_istype(char c);
//ft_swprint.c
int		ft_printarg1(va_list argptr, char c);
int		ft_printarg2(va_list argptr, char c);
int		ft_printarg3(va_list argptr, char c);
int		ft_swprint(va_list argptr, char c);
//ft_putone.c
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int nbr, int *count);
void	ft_putnbru(unsigned int nbr, int *count);
//ft_puttwo.c
int		ft_putnbrbase(unsigned int nbr, char *base);
int		ft_putnbrbasel(long long unsigned int nbr, char *base);

#endif
