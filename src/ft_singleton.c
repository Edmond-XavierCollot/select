/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:33:43 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/08 10:37:14 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	*ft_get_caps(void)
{
	static t_select	*caps;

	if (caps == NULL)
		caps = (t_select *)malloc(sizeof(*caps));
	return (caps);
}
