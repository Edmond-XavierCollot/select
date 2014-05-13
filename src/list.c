/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 13:14:09 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 17:16:10 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

void			list_re_join(t_caps *caps)
{
	int			line;
	t_select	*choices;

	choices = caps->head;
	line = 0;
	while (1)
	{
		choices->posl = line;
		choices->posc = 0;
		line = line + 1;
		if (choices == (t_select *)caps->tail)
			break ;
		choices = choices->next;
	}
}

static int		ft_len_max(t_select **choices, int li)
{
	int		len_max;
	int		len_name;

	len_max = 0;
	while ((*choices)->li < li)
	{
		len_name = ft_strlen((*choices)->name);
		if (len_name > len_max)
				len_max = len_name;
		if ((*choices) == (*choices)->caps->tail)
			break ;
		(*choices) = (*choices)->next;
	}
	return (len_max);
}

static t_select	*ft_change_row(t_select *choices, int len_max, int li)
{
	t_select	*tmp;
	int			line;

	line = 0;
	tmp = choices;
	while (line < li)
	{
		choices->co = len_max + 1;
		choices->li = line;
		line = line + 1;
		if (choices == choices->caps->tail)
				break ;
		choices = choices->next;
	}
	return (tmp);
}

void			list_re_init(t_caps *caps, int li)
{
	t_select	*choices;
	int			len_max;
	int			max;
	int			i;

	i = 1;
	max = 0;
	choices = caps->head;
	while (1)
	{
		len_max = ft_len_max(&choices, li) + max;
		if (choices == caps->tail && choices->li < li)
			break ;
		choices = ft_change_row(choices, len_max, li);
		len_max = len_max - max;
		if (choices == caps->tail)
			break ;
		max = max + len_max + 1;
		i = i + 1;
	}
}
