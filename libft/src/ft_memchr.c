/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:43:41 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:30:18 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (*((char *)s) == (char)c)
			return ((void *)s);
		s = s + 1;
		i = i + 1;
	}
	return (NULL);
}
