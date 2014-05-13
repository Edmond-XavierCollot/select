/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:13:26 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 21:51:36 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if (ft_strlen(s2) > n)
		return (NULL);
	while (*s1 != '\0')
	{
		i = 0;
		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		{
			i = i + 1;
		}
		if (s2[i] == '\0' || s2[i] == s1[i] || ft_strlen(s2) == 0)
		{
			return ((char *)s1);
		}
		s1 = s1 + 1;
	}
	return (NULL);
}
