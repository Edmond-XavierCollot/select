/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 18:05:48 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 17:32:48 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <signal.h>

void		ft_stop(int i)
{
	char		susp[2];
	t_caps		*caps;
	t_termios	*term;

	(void)i;
	if (isatty(1))
	{
		caps = (t_caps *)ft_get_caps();
		term = caps->term;
		tputs(tgetstr("te", NULL), 1, my_putchar);
		tputs(tgetstr("ke", NULL), 1, my_putchar);
		susp[0] = term->c_cc[VSUSP];
		susp[1] = '\0';
		term->c_lflag = (ISIG | ECHOE);
		tcsetattr(0, 0, term);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, susp);
	}
}

void		ft_recup(int i)
{
	t_caps		*caps;

	(void)i;
	caps = (t_caps *)ft_get_caps();
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	tputs(tgetstr("ks", NULL), 1, my_putchar);
	tcsetattr(0, 0, caps->term);
	signal(SIGTSTP, ft_stop);
	re_draw(caps);
}


void		ft_kill(int i)
{

	t_caps	*caps;
	caps = (t_caps *)ft_get_caps();
	tputs(tgetstr("ke", NULL), 1, my_putchar);
	ft_exit(caps, 1);
	(void)i;
}

void		ft_resize(int i)
{
	(void)i;
	re_draw((t_caps *)ft_get_caps());
}

int			main(int ac, char **av)
{
	t_termios		term;
	t_caps			*caps;

	signal(SIGWINCH, ft_resize);
	signal(SIGCONT, ft_recup);
	signal(SIGKILL, ft_kill);
	signal(SIGQUIT, ft_kill);
	signal(SIGINT, ft_kill);
	signal(SIGTSTP, ft_stop);
	caps = ft_parsor(ac, av + 1);
	term_init();
	term_raw(&term);
	caps->term = &term;
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	re_draw(caps);
	while (1)
		ft_read(caps);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	term_default(&term);
	return (0);
}
