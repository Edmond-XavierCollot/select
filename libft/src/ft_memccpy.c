/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:36:52 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/30 13:16:29 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
		char		*mem;
		const char	*src;
		char		c2;

	if (n)
	{
		mem = s1;
		src = s2;
		c2 = c;
		while (n != 0)
		{
			*mem = *src;
			if (*src == c2)
			{
				mem = mem + 1;
				return (mem);
			}
			src = src + 1;
			mem = mem + 1;
			n = n - 1;
		}
	}
	return (0);
}
