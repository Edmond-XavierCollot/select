/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:32:16 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:31:09 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putnbr(int nbr)
{
	int		ret;

	ret = 0;
	if (nbr == -2147483648)
	{
		ret = write(1, "-2147483648", 11);
		return (ret);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ret = ret + 1;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ret = ret + ft_putnbr(nbr / 10);
	}
	ft_putchar('0' + (nbr % 10));
	ret = ret + 1;
	return (ret);
}
