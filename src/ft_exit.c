/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:23:01 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 17:44:48 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_free_list(t_caps *caps)
{
	t_select	*tmp;
	t_select	*choices;

	choices = caps->head;
	while (1)
	{
		if (choices == caps->tail)
			{
				free(choices);
				break ;
			}
		tmp = choices->next;
		free(choices);
		choices = tmp;
	}
	free(caps);
}

void		ft_exit(t_caps *caps, int i)
{
	int		fd;

	if (i == 1)
	{
		term_default(caps->term);
		tputs(tgetstr("te", NULL), 1, my_putchar);
	}
	fd = open("/dev/tty", O_RDWR);
	if (close(fd) == -1)
		ft_putstr_fd("can't close the term's file desriptor", 2);
	ft_free_list(caps);
	exit(0);
}
