# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:56:33 by msimoes           #+#    #+#              #
#    Updated: 2025/10/27 11:36:26 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_aux.a
AUXS = ft_calloc.c ft_split.c ft_split2.c ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strjoin.c list_funcs.c lst_init.c ft_strcmp.c $(PTF_F)

PTF = ft_printerr/
PTF_F = $(PTF)ft_handle_hex.c $(PTF)ft_handle_point.c $(PTF)ft_printerror.c \
		$(PTF)ft_printf.c $(PTF)ft_putchar_fd.c $(PTF)ft_putdecimal_int.c \
		$(PTF)ft_putnbr_fd.c $(PTF)ft_putstr_fd.c

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
