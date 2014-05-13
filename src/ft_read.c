/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 17:22:39 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 17:25:08 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_read(t_caps *caps)
{
	int				ret;
	unsigned int	buf;
	char			read_char[5];

	read_char[0] = 0;
	read_char[1] = 0;
	read_char[2] = 0;
	read_char[3] = 0;
	read_char[4] = 0;
	tputs(tgetstr("ks", NULL), 1, my_putchar);
	if ((ret = read(0, read_char, 4)) == -1)
	{
		tputs(tgetstr("te", NULL), 1, my_putchar);
		term_default(caps->term);
		ft_exit(caps, 1);
	}
	buf = *(unsigned int *)read_char;
	tputs(tgetstr("ke", NULL), 1, my_putchar);
	term_event(buf, caps);
}
