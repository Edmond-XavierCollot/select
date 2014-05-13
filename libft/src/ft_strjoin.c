/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:56:27 by ecollot           #+#    #+#             */
/*   Updated: 2014/05/13 17:54:57 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strjoins2(char *new, char const *s2, size_t i, size_t len)
{
	while (s2[len] != '\0')
	{
		new[i] = s2[len];
		i = i + 1;
		len = len + 1;
	}
	new [i] = '\0';
	return (new);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*new;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((new = (char *)malloc(sizeof(new) * (len + 1))) == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		new[i] = s1[len];
		i = i + 1;
		len = len + 1;
	}
	len = 0;
	new = ft_strjoins2 (new, s2, i, len);
	return (new);
}
