/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 11:46:44 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/22 18:31:59 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_checkflag(va_list *ap, char **str)
{
	if (**str != '%')
		return (0);
	*str = *str + 1;
	while (**str == ' ')
		*str = *str + 1;
	if (**str == '%')
		return (0);
	return (ft_checktype(ap, str));
}
