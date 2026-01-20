# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:56:33 by msimoes           #+#    #+#              #
#    Updated: 2025/10/28 11:29:19 by msimoes          ###   ########.fr        #
=======
#    By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:56:33 by msimoes           #+#    #+#              #
#    Updated: 2026/01/05 14:06:35 by vampaier2        ###   ########.fr        #
>>>>>>> origin/parcing
#                                                                              #
# **************************************************************************** #

NAME = lib_aux.a
<<<<<<< HEAD
AUXS = ft_calloc.c ft_split.c ft_split2.c ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strjoin.c list_funcs.c lst_init.c ft_strcmp.c ft_findchar.c \
		$(PTE_F) 

PTE = ft_printerr/
PTE_F = $(PTE)ft_handle_hex.c $(PTE)ft_handle_point.c $(PTE)ft_printerror.c \
		$(PTE)ft_printf.c $(PTE)ft_putchar_fd.c $(PTE)ft_putdecimal_int.c \
		$(PTE)ft_putnbr_fd.c $(PTE)ft_putstr_fd.c
=======
AUXS = ft_calloc.c ft_split.c ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strjoin.c list_funcs.c signal_funcs.c ft_free.c \
		ft_strnstr.c ft_striteri.c ft_strcmp.c
>>>>>>> origin/parcing

COMP_LIB = ar rcs
RM = rm -f
CC = cc
CC_FLAGS = -Wall -Wextra -Werror

OBJS = $(AUXS:.c=.o)

%.o : %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(COMP_LIB) $(NAME) $(OBJS)

.PHONY: all clean fclean re
