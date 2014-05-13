/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:01:40 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 21:47:37 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	buf[n];

	i = 0;
	while (i < n)
	{
		buf[i] = ((unsigned char *)s2)[i];
		i = i + 1;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)s1)[i] = buf[i];
		i = i + 1;
	}
	return (s1);
}
