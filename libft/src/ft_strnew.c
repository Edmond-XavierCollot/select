/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:53:48 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 21:46:28 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char *)malloc(size)))
	{
		while (i < (int)size)
		{
			str[i] = '\0';
			i = i + 1;
		}
		return (str);
	}
	else
		return (NULL);
}

