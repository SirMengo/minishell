# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 11:01:52 by msimoes           #+#    #+#              #
#    Updated: 2025/11/07 11:25:03 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PENV = envars/
ENV = $(PENV)envars.c $(PENV)find_envars.c

PEXP = exports/
EXP = $(PEXP)exports_parsing.c $(PEXP)exports.c

PUNS = unset/
UNS = $(PUNS)unset.c

NAME = lib_builtin.a
AUXS = $(ENV) $(EXP) $(UNS)

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