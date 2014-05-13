/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:34:52 by ecollot           #+#    #+#             */
/*   Updated: 2014/01/11 18:37:15 by ecollot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUF_SIZE 4600
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <ft_printf.h>

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void ** ap);
void	ft_bzero(void *s, size_t n);
void	ft_strdel(char **as);
int		ft_putnbr(int nbr);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr(const char *str);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl(const char *str);
void	ft_putendl_fd(const char *str, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	**ft_strsplit(char const *s, char c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *str1);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	*ft_itoa(int nbr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *strc);
int		ft_isalpha(int a);
int		ft_isdigit(int a);
int		ft_isalnum(int a);
int		ft_isascii(int a);
int		ft_isprint(int a);
int		ft_toupper(int a);
int		ft_tolower(int a);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		get_next_line(int const fd, char **line);

#endif
