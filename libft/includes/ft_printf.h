/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 11:31:53 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/03 11:07:31 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

int		ft_printf(const char *format, ...);
int		ft_checkflag(va_list *ap, char **arg);
int		ft_checktype(va_list *ap, char **arg);
int		ft_putnbr(int nbr);
int		ft_putunbr(size_t nbr);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
char	*ft_itoa(int nbr);
int		ft_putpf_d(va_list *ap, char **str);
int		ft_putpf_o(int nbr);
int		ft_putpf_x(int nbr, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif
