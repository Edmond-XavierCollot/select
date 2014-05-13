# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecollot <ecollot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 13:54:07 by ecollot           #+#    #+#              #
#    Updated: 2014/01/24 17:17:25 by ecollot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = cc

SRC = src/main.c			\
	  src/term_data.c		\
	  src/parsor.c			\
	  src/print.c			\
	  src/ft_exit.c			\
	  src/select.c			\
	  src/list.c			\
	  src/ft_singleton.c	\
	  src/ft_check_size.c	\
	  src/ft_read.c

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJDIR = .obj

SRCDIR = src

LIBDIR = libft
	
CFLAGS = -Wextra -Wall -Werror -I./includes -I./libft/includes/

.SILENT :

all: $(NAME)

$(addprefix $(OBJDIR)/, %.o)	: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	printf '\033[1;35m[CREATE OBJECT] $@\n\033[0m' "Building C Object $@"	

$(NAME): $(OBJDIR) $(OBJ)
	make -C $(LIBDIR)/
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) -L$(LIBDIR)/ -lft  -L /usr/lib -ltermcap $(OBJ)
	printf '\033[7;94m%s \033[1;35m%s \033[1;33m%s\n\n\033[0m' "[COMPILATION COMPLETE]" "$(NAME)" "$(CC)"

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/src

clean:
	rm -rf $(OBJ) $(OBJDIR)
	make -C $(LIBDIR)/ clean

debug :
fclean: clean
	rm -rf $(NAME) $(OBJ)
	make -C $(LIBDIR)/ fclean

re: fclean all
