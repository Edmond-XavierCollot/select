/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:30:19 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 21:53:01 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c2;

	c2 = c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c2;
		i = i + 1;
	}
	return (b);
}
