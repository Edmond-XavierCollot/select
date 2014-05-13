/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 09:39:54 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 17:17:13 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	move_down(t_caps *caps)
{
	t_select	*choices;

	choices = caps->cursor;
	choices->cursor = 0;
	choices->next->cursor = 1;
	caps->cursor = choices->next;
	draw(caps, choices);
}

void	move_top(t_caps *caps)
{
	t_select	*choices;

	choices = caps->cursor;
	choices->cursor = 0;
	choices->prev->cursor = 1;
	caps->cursor = choices->prev;
	draw(caps, choices);
}

void	ft_return(t_caps *caps)
{
	int			i;
	t_select	*choices;

	choices = caps->head;
	tputs(tgetstr("te", NULL), 1, my_putchar);
	term_default(caps->term);
	i = 0;
	while (1)
	{
		if (choices->select == 1)
		{
			if (i > 0)
				ft_putchar(' ');
			i = i + 1;
			ft_putstr(choices->name);
		}
		if (choices == choices->caps->tail)
			break ;
		choices = choices->next;
	}
	ft_exit(caps, 0);
}

void	ft_delete(t_caps *caps)
{
	t_select	*tmp;
	t_select	*choices;

	choices = caps->cursor;
	if (choices->next == choices)
		term_event(27, caps);
	tmp = choices->prev;
	tmp->next = choices->next;
	if (choices == caps->tail)
		caps->tail = tmp;
	tmp = choices->next;
	tmp->prev = choices->prev;
	if (choices == caps->head)
		caps->head = tmp;
	free(choices);
	caps->cursor = tmp;
	tmp->cursor = 1;
	caps->size = caps->size - 1;
	list_re_join(caps);
	re_draw(caps);
}

void	ft_select(t_caps *caps)
{
	t_select	*choices;

	choices = caps->cursor;
	if (choices->select == 1)
		choices->select = 0;
	else
		choices->select = 1;
	move_down(caps);
}
