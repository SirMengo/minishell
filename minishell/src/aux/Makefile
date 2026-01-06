# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:56:33 by msimoes           #+#    #+#              #
#    Updated: 2026/01/05 14:06:35 by vampaier2        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_aux.a
AUXS = ft_calloc.c ft_split.c ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strjoin.c list_funcs.c signal_funcs.c ft_free.c \
		ft_strnstr.c ft_striteri.c ft_strcmp.c

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
