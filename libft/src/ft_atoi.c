/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <edxcollot@hotmail.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/04 16:24:13 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:29:37 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_atoi_skip2(char *str)
{
	if (*str == '\v' || *str == '\t' || *str == '\r' || *str == '\f')
	{
		return (1);
	}
	else
		return (0);
}

static char	*ft_atoi_skip(char *str, char *positive)
{
	while (*str == ' ' || (ft_atoi_skip2(str)) || *str == '\n')
	{
		str = str + 1;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			*positive = 0;
		}
		str = str + 1;
	}
	return (str);
}

int			ft_atoi(const char *strc)
{
	int		ret;
	char	positive;
	char	*str;

	str = (char *)malloc(sizeof(str) * (ft_strlen(strc) + 1));
	if (str == NULL)
		return (0);
	str = ft_strdup(strc);
	ret = 0;
	positive = 1;
	str = ft_atoi_skip(str, &positive);
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		ret = ret * 10;
		ret = ret + (*str - '0');
		str = str + 1;
	}
	if (positive == 0)
	{
		ret = ret * -1;
	}
	return (ret);
}
