/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:50:03 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 21:49:58 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*new;
	size_t		i;
	size_t		j;

	if (s == NULL || f == NULL)
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	new = (char *)malloc(sizeof(new) * (i + 1));
	if (new == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		new[j] = f(j, (char)s[j]);
		j = j + 1;
	}
	new[j] = '\0';
	return (new);
}
