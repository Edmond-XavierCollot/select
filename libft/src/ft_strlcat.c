/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:17:16 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 22:01:24 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = (char *)src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d = d + 1;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n = n - 1;
		}
		s = s + 1;
	}
	*d = '\0';
	return (dlen + (s - src));
}
