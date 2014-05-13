/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 09:55:44 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:10:57 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_linecpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (src[i] == '\0' || src[i] == '\n')
			break ;
		dest[i] = src[i];
		i = i + 1;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i = i + 1;
	}
	return (dest);
}

static char	*ft_stradd(char *buf, char *tmp)
{
	int		len;
	char	*tmp2;

	len = ft_strlen(buf) + 1;
	tmp2 = (char *) malloc(sizeof(tmp2) * len);
	tmp2 = ft_strncpy(tmp2, buf, len);
	free(buf);
	buf = (char *) malloc(sizeof(buf) * (len + BUF_SIZE));
	buf = ft_strncpy(buf, tmp2, len);
	buf = ft_strcat(buf, tmp);
	buf[len + BUF_SIZE] = '\0';
	free(tmp2);
	return (buf);
}

static int	ft_linelen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i = i + 1;
	return (i);
}

static int	ft_addline(char **line, char **buf)
{
	int		j;

	j = ft_linelen(*buf) + 1;
	if ((*line = (char *) malloc(sizeof(*line) * j)) && **buf != '\0')
	{
		*line = ft_linecpy(*line, *buf, j);
		*buf = *buf + j;
		return (1);
	}
	if (*line == NULL)
		return (-1);
	else
		return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	char		*tmp;
	int			ret;
	int			j;
	static int	i;

	if (buf == NULL || fd != i)
	{
		i = fd;
		tmp = (char *) malloc(sizeof(tmp) * (BUF_SIZE + 1));
		buf = (char *) malloc(sizeof(buf) * (BUF_SIZE + 1));
		if (tmp == NULL || buf == NULL)
			return (-1);
		while ((ret = read(fd, tmp, BUF_SIZE)))
		{
			if (ret == -1)
				return (-1);
			tmp[ret] = '\0';
			buf = ft_stradd(buf, tmp);
		}
	}
	j = ft_addline(line, &buf);
	return (j);
}
