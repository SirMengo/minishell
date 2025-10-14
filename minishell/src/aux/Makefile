# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:56:33 by msimoes           #+#    #+#              #
#    Updated: 2025/10/13 15:42:37 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_aux.a
AUXS = ft_calloc.c ft_split.c ft_split2.c ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strjoin.c ft_free.c ft_strnstr.c ft_lstadd_back.c ft_lstnew.c 

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

