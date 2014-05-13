/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:22:38 by ecollot           #+#    #+#             */
/*   Updated: 2013/12/30 13:13:38 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_no_more_line(char *new, const char *s, int i, int len)
{
	new[len] = s[i];
	new[len + 1] = '\0';
}

static int	ft_strlenskip(char const *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while ((str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			&& str[i] != '\0')
		i = i + 1;
	if (str[i] == '\0')
		return (0);
	j = len;
	j = j - i;
	i = len - 1;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
	{
		i = i - 1;
		j = j - 1;
	}
	return (j - 1);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		end;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlenskip(s);
	if ((new = (char *)malloc(sizeof(new) * (len + 1))) == NULL)
		return (NULL);
	if (len == (int)ft_strlen(s))
		return (ft_strcpy(new, s));
	while ((s[i] == '\n' || s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
		i = i + 1;
	end = i + len;
	len = 0;
	while (i < end && s[i] != '\0')
	{
		new[len] = s[i];
		i = i + 1;
		len = len + 1;
	}
	ft_no_more_line(new, s, i, len);
	return (new);
}
