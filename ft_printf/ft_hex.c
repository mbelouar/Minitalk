/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:01:12 by mbelouar          #+#    #+#             */
/*   Updated: 2022/10/25 17:43:43 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long long nb, char *base)
{
	int		tmp;

	tmp = 0;
	if (nb < 16)
		tmp += ft_putchar(base[nb]);
	else if (nb >= 16)
	{
		tmp += ft_hex(nb / 16, base);
		tmp += ft_hex(nb % 16, base);
	}
	else
		tmp += ft_putchar(nb + 48);
	return (tmp);
}
