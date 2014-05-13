/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 16:55:47 by ecollot           #+#    #+#             */
/*   Updated: 2014/05/13 17:53:08 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_select.h>

int		ft_check_size(t_caps *caps)
{
	t_select	*choices;
	int			max;
	int			co;

	co = tgetnum("co");
	term_init();
	choices = caps->head;
	while (1)
	{
		max = ft_strlen(choices->name) + choices->co;
		if (max > co)
		{
			tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
			tputs(tgetstr("cd", NULL), 1, my_putchar);
			my_putstr("resize your window");
			return (-1);
		}
		if (choices == caps->tail)
			break ;
		choices = choices->next;
	}
	return (0);
}
