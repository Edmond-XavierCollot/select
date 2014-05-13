/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 13:51:10 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 17:33:48 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		check_arg_error(int ac, char **av)
{
	if (av == NULL)
	{
		ft_putstr_fd("fatal : argument error", 2);
		exit (0);
	}
	else if (ac < 2)
	{
		ft_putstr_fd("usage : <choice1> <choice2> ... <choicen>", 2);
		exit (0);
	}
}

static t_select	*ft_add_choices(t_select *choices, char *name)
{
	t_select	*tmp;

	tmp = (t_select *)malloc(sizeof(*tmp));
	choices->next = tmp;
	tmp->next = choices;
	tmp->prev = choices;
	tmp->caps = choices->caps;
	tmp->name = ft_strdup(name);
	tmp->caps->size = tmp->caps->size + 1;
	tmp->select = 0;
	tmp->cursor = 0;
	tmp->li = tmp->prev->li + 1;
	tmp->co = 0;
	tmp->posc = 0;
	tmp->posl = tmp->li;
	return (tmp);
}

static t_caps	*first_choices_init(char **av)
{
	t_select	*choices;
	t_caps		*caps;

	choices = (t_select *)malloc(sizeof(*choices));
	caps = (t_caps *)ft_get_caps();
	caps->size = 1;
	caps->head = choices;
	caps->cursor = choices;
	choices->caps = caps;
	choices->next = choices;
	choices->prev = choices;
	choices->name = ft_strdup(*av);
	choices->select = 0;
	choices->cursor = 1;
	choices->li = 0;
	choices->posl = 0;
	choices->co = 0;
	choices->posc = 0;
	return (caps);
}

static t_caps	*choices_init(char **av)
{
	t_select	*choices;
	t_caps		*caps;

	caps = first_choices_init(av);
	choices = caps->head;
	av = av + 1;
	while (*av != '\0')
	{
		choices = ft_add_choices(choices, *av);
		av = av + 1;
	}
	caps->tail = choices;
	caps->head->prev = choices;
	choices->next= caps->head;
	return (caps);
}

t_caps			*ft_parsor(int ac, char **av)
{
	check_arg_error(ac, av);
	return (choices_init(av));
}
