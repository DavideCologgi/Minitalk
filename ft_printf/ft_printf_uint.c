/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:59:47 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/08 15:40:38 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	if (nb == 4294967295)
	{
		ft_putnbr(nb / 10);
		ft_putchar('5');
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	if (nb < 0)
		return (ll_lenght(4294967295 - nb + 1, 10));
	return (ll_lenght(nb, 10));
}
