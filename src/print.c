/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 17:30:01 by ecollot           #+#    #+#             */
/*   Updated: 2014/05/13 17:52:53 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <fcntl.h>

int		my_putchar(int c)
{
	static int	fd = -1;

	if (fd == -1)
	{
		if ((fd = open("/dev/tty", O_RDWR)) == -1)
		{
			ft_putstr_fd("fail to open /dev/tty", 2);
			tputs(tgetstr("te", NULL), 1, my_putchar);
			term_default(((t_caps *)ft_get_caps())->term);
			exit(0);
		}
	}
	return (write(fd, &c, 1));
}

int		my_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i = i + 1;
	}
	return (i);
}

void	re_draw2(t_caps *caps)
{
	int			li;
	t_select	*choices;

	choices = caps->head;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	tputs(tgetstr("cd", NULL), 1, my_putchar);
	while (1)
	{
		li = choices->li;
		tputs(tgoto(tgetstr("cm", NULL), choices->co, li ), 1, my_putchar);
		if (choices->cursor == 1)
			tputs(tgetstr("us", NULL), 1, my_putchar);
		if (choices->select == 1)
			tputs(tgetstr("mr", NULL), 1, my_putchar);
		my_putstr(choices->name);
		if (choices->cursor == 1)
			tputs(tgetstr("ue", NULL), 1, my_putchar);
		if (choices->select == 1)
			tputs(tgetstr("me", NULL), 1, my_putchar);
		if (caps->tail == choices)
			break ;
		choices = choices->next;
	}
	choices = caps->cursor;
	tputs(tgoto(tgetstr("cm", NULL), choices->co, choices->li), 1, my_putchar);
	choices = caps->head;
}

void	re_draw(t_caps *caps)
{
	int			li;
	t_select	*choices;

	choices = caps->head;
	while (1)
	{
		choices->li = choices->posl;
		choices->co = choices->posc;
		if (choices == caps->tail)
			break ;
		choices = choices->next;
	}
	term_init();
	li = tgetnum("li");
	if (caps->size > li)
		list_re_init(caps, li);
	choices = caps->head;
	if (ft_check_size(caps) == -1)
		return ;
	re_draw2(caps);
}

void	draw(t_caps *caps, t_select *prev)
{
	t_select	*choices;

	choices = caps->cursor;
	tputs(tgoto(tgetstr("cm", NULL), prev->co, prev->li), 1, my_putchar);
	if (prev->select == 1)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	my_putstr(prev->name);
	if (prev->select == 1)
		tputs(tgetstr("me", NULL), 1, my_putchar);
	choices = choices->caps->cursor;
	tputs(tgoto(tgetstr("cm", NULL), choices->co, choices->li), 1, my_putchar);
	tputs(tgetstr("us", NULL), 1, my_putchar);
	if (choices->select == 1)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	my_putstr(choices->name);
	if (choices->select == 1)
		tputs(tgetstr("me", NULL), 1, my_putchar);
	tputs(tgetstr("ue", NULL), 1, my_putchar);
	tputs(tgoto(tgetstr("cm", NULL), choices->co, choices->li), 1, my_putchar);
	choices = caps->head;
}
