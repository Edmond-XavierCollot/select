# p
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 13:54:07 by ecollot           #+#    #+#              #
#    Updated: 2014/01/03 11:32:55 by ecollot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

SRC = src/ft_strlen.c				\
	  src/ft_strcpy.c				\
	  src/ft_isalpha.c				\
	  src/ft_isdigit.c				\
	  src/ft_isalnum.c				\
	  src/ft_isascii.c				\
	  src/ft_isprint.c				\
	  src/ft_toupper.c				\
	  src/ft_tolower.c				\
	  src/ft_strdup.c				\
	  src/ft_strncpy.c				\
	  src/ft_strcat.c				\
	  src/ft_strncat.c				\
	  src/ft_strchr.c				\
	  src/ft_strstr.c				\
	  src/ft_strnstr.c				\
	  src/ft_strrchr.c				\
	  src/ft_atoi.c					\
	  src/ft_strcmp.c				\
	  src/ft_strncmp.c				\
	  src/ft_memset.c				\
	  src/ft_memcpy.c				\
	  src/ft_memccpy.c				\
	  src/ft_bzero.c				\
	  src/ft_memchr.c				\
	  src/ft_memmove.c				\
	  src/ft_memcmp.c				\
	  src/ft_strlcat.c				\
	  src/ft_memalloc.c				\
	  src/ft_strdel.c				\
	  src/ft_strnew.c				\
	  src/ft_strclr.c				\
	  src/ft_striter.c				\
	  src/ft_striteri.c				\
	  src/ft_strmap.c				\
	  src/ft_strmapi.c				\
	  src/ft_memdel.c				\
	  src/ft_strequ.c				\
	  src/ft_strnequ.c				\
	  src/ft_strsub.c				\
	  src/ft_strjoin.c				\
	  src/ft_strsplit.c				\
	  src/ft_strtrim.c				\
	  src/ft_itoa.c					\
	  src/ft_putchar.c				\
	  src/ft_putchar_fd.c			\
	  src/ft_putstr.c				\
	  src/ft_putstr_fd.c			\
	  src/ft_putendl.c				\
	  src/ft_putendl_fd.c			\
	  src/ft_putnbr.c				\
	  src/ft_putnbr_fd.c			\
	  src/get_next_line.c			\
	  src/ft_printf.c				\
	  src/ft_checkflag.c			\
	  src/ft_checktype.c			\
	  src/ft_putunbr.c				\
	  src/ft_putpf_o.c				\
	  src/ft_putpf_x.c				\
	  src/ft_putpf_d.c


OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJDIR = .obj

SRCDIR = src

CFLAGS = -Wextra -Wall -Werror -I./includes

.SILENT :

all: $(NAME)

$(addprefix $(OBJDIR)/, %.o)	: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	printf '\033[1;35m[CREATE LIB-OBJECT] $@\n\033[0m' "Building C Object $@"

$(NAME): $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	printf '\033[4;92mLib has been created with success\033[0m\n'

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/src

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME) $(OBJ)

re: fclean all
