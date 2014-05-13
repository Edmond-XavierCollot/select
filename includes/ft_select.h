/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 10:09:26 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:38:29 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <libft.h>
# include <sys/ioctl.h>

typedef struct		termios t_termios;

typedef struct		s_caps
{
	struct s_select	*head;
	struct s_select	*tail;
	struct s_select	*cursor;
	t_termios		*term;
	int				size;
}					t_caps;

typedef struct		s_select
{
	struct s_select	*next;
	struct s_select	*prev;
	char			*name;
	int				select;
	int				cursor;
	int				li;
	int				co;
	int				posl;
	int				posc;
	t_caps			*caps;
}					t_select;

int			my_putchar(int c);
int			my_putstr(char *str);
int			ft_check_size(t_caps *caps);
void		term_init(void);
void		draw(t_caps *caps, t_select *prev);
void		re_draw(t_caps *caps);
void		re_draw2(t_caps *caps);
void		ft_exit(t_caps *caps, int i);
void		ft_select(t_caps *caps);
void		ft_delete(t_caps *caps);
void		ft_return(t_caps *caps);
void		move_down(t_caps *caps);
void		move_top(t_caps *caps);
void		term_raw(t_termios *term);
void		term_default(t_termios *term);
void		term_event(unsigned int key, t_caps *caps);
void		*ft_get_caps(void);
void		ft_read(t_caps *caps);
void		list_re_join(t_caps *caps);
void		list_re_init(t_caps *caps, int li);
t_caps		*ft_parsor(int ac, char **av);

#endif
