# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:56:33 by msimoes           #+#    #+#              #
#    Updated: 2025/12/09 11:24:34 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_aux.a
AUXS = ft_calloc.c ft_split.c ft_split2.c ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strjoin.c list_funcs.c lst_init.c ft_strcmp.c ft_findchar.c \
		list_funcs.c lst_init.c ft_isalpha.c ft_isalnum.c $(PTE_F) 

PTE = ft_printerr/
PTE_F = $(PTE)ft_handle_hex.c $(PTE)ft_handle_point.c $(PTE)ft_printerror.c \
		$(PTE)ft_printf.c $(PTE)ft_putchar_fd.c $(PTE)ft_putdecimal_int.c \
		$(PTE)ft_putnbr_fd.c $(PTE)ft_putstr_fd.c

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
