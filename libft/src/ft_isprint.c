/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:42:43 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/02 15:19:55 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int a)
{
	return (a >= 32 && a <= 126);
}
