/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:16:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/15 09:06:53 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<stdbool.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		lenght(int nb, int base);
int		ll_lenght(long long nb, int base);

void	ft_printhex(unsigned int nb, const char formato);
int		ft_hexlen(unsigned int nb);
int		ft_puthexnbr(unsigned int nb, const char formato);

int		ft_putnbr(int nb);

void	ft_printptr(uintptr_t p);
int		ft_ptrlen(uintptr_t p);
int		ft_putptr(uintptr_t ptr);

int		ft_putunbr(unsigned int nb);

int		ft_printer(va_list lista_parametri, const char tipo);
int		ft_printf(const char *a, ...);

#endif
