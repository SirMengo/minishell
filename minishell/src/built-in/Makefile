# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 11:01:52 by msimoes           #+#    #+#              #
#    Updated: 2026/01/07 15:15:56 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PCD = cd/
CD = $(PCD)cd.c $(PCD)create_entry.c

PECHO = echo/
ECHO = $(PECHO)echo.c

PENV = envars/
ENV = $(PENV)envars.c $(PENV)find_envars.c $(PENV)init_envars.c

PEXIT = exit/
EXIT = $(PEXIT)exit.c

PEXP = exports/
EXP = $(PEXP)add_update.c $(PEXP)exports_parsing.c $(PEXP)exports.c $(PEXP)init_exports.c

PPWD = pwd/
PWD = $(PPWD)pwd.c

PUNS = unset/
UNS = $(PUNS)unset.c

NAME = lib_builtin.a
AUXS = $(CD) $(ECHO) $(ENV) $(EXIT) $(EXP) $(PWD) $(UNS)

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