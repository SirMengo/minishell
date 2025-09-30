# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 10:25:50 by msimoes           #+#    #+#              #
#    Updated: 2025/09/30 11:08:31 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = src/main.c
AUX_LIB = src/aux/lib_aux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lreadline -ltermcap
RM = rm -f

OBJS = $(SRCS:.c=.o)

$(AUX_LIB):
	$(MAKE) -C src/aux

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(AUX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(AUX_LIB) -o $(NAME) && echo "Compiled"

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C src/aux clean
	rm -f src/aux/lib_aux.a

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re
