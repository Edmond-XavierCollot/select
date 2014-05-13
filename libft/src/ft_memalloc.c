/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:47:37 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/15 22:00:33 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char		*mem;
	size_t		i;

	i = 0;
	if ((mem = (char *)malloc((sizeof(mem) * size))))
	{
		while (i < size)
		{
			(mem)[i] = '\0';
			i = i + 1;
		}
		return (mem);
	}
	else
		return (NULL);
}
