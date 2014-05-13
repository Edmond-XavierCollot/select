/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:36:23 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:32:19 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = (size_t)start;
	new = (char *)malloc(sizeof(new) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (len > 0)
	{
		new[j] = s[i];
		i = i + 1;
		j = j + 1;
		len = len - 1;
	}
	new[j] = '\0';
	return (new);
}
