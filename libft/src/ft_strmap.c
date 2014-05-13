/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:20:12 by ecollot           #+#    #+#             */
/*   Updated: 2014/05/13 17:54:40 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*new;
	size_t		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	new = (char *)malloc(sizeof(new) * (i + 1));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f((char)s[i]);
		i = i + 1;
	}
	new[i] = '\0';
	return (new);
}
