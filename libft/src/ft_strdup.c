/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:39:58 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/30 18:37:35 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = ft_strlen(s1);
	if ((s2 = (char *)malloc(sizeof(s2) * (len + 1))) == NULL)
			return (NULL);
	if (s2 == NULL)
		return (NULL);
	while (i <= len)
	{
		s2[i] = s1[i];
		i = i + 1;
	}
	return (s2);
}
