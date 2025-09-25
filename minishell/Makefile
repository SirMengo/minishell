# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 10:25:50 by msimoes           #+#    #+#              #
#    Updated: 2025/09/24 16:30:53 by xalves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS =

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lreadline -ltermcap
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) && echo "Compiled"

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re
