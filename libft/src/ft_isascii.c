/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:20:10 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/02 15:19:27 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
