/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 10:08:50 by ecollot           #+#    #+#             */
/*   Updated: 2014/02/03 17:33:42 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	term_init(void)
{
	char		*bp;
	char		*term;
	int			success;

	term = getenv("TERM");
	if (term == 0)
	{
		ft_putstr_fd("Specify a terminal type with `setenv TERM '.\n", 2);
		exit(1);
	}
	bp = (char *)malloc(sizeof(*bp));
	success = tgetent(bp, term);
	if (success < 0)
	{
		ft_putstr_fd("error : Could not access the termcap data base.\n", 2);
		free(bp);
		exit(1);
	}
	if (success == 0)
	{
		ft_putstr_fd("error :Terminal type `%s' is not defined.\n", 2);
		exit(1);
	}
}

void	term_raw(t_termios *term)
{
	tcgetattr(0, term);
	term->c_lflag |= ISIG;
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

void	term_default(t_termios *term)
{
	term->c_lflag |= (ISIG | ICANON | ECHO | ECHOCTL | ECHOKE | ECHOE);
	term->c_lflag |= (IEXTEN | IUTF8);
	tcsetattr(0, 0, term);
}

void	term_event(unsigned int key, t_caps *caps)
{
	if (key == 27)
		ft_exit(caps, 1);
	else if (ft_check_size(caps) == -1)
		return ;
	else if (key == 4345627)
		move_down(caps);
	else if (key == 4280091)
		move_top(caps);
	else if (key == 32)
		ft_select(caps);
	else if (key == 127 || key == 2117294875)
		ft_delete(caps);
	else if (key == 10 || key == 5066523)
		ft_return(caps);
}
