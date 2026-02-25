# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 12:36:11 by msimoes           #+#    #+#              #
#    Updated: 2026/02/24 11:33:34 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = minishell
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -lreadline -lncurses

OBJ_DIR = obj

# ─── Sources ────────────────────────────────────────────────────────────────

SRC_MAIN = \
	src/main.c \
	src/history.c \
	src/signal.c \
	src/signal_toggle.c

SRC_ARG_PARSER = \
	src/arg_parser/arg_parser.c \
	src/arg_parser/aux.c \
	src/arg_parser/open_close.c

SRC_AUX = \
	src/aux/ft_calloc.c \
	src/aux/ft_split.c \
	src/aux/ft_strdup.c \
	src/aux/ft_substr.c \
	src/aux/ft_strlen.c \
	src/aux/ft_strjoin.c \
	src/aux/lst_init.c \
	src/aux/ft_strcmp.c \
	src/aux/ft_findchar.c \
	src/aux/ft_list_funcs.c \
	src/aux/ft_isalpha.c \
	src/aux/ft_isalnum.c \
	src/aux/get_list.c \
	src/aux/ft_atoi.c \
	src/aux/ft_itoa.c \
	src/aux/ft_memset.c \
	src/aux/ft_strchr.c \
	src/aux/arr_size.c \
	src/aux/ft_lstsize.c \
	src/aux/ft_strnstr.c \
	src/aux/ft_isnum.c \
	src/aux/ft_printerr/ft_handle_hex.c \
	src/aux/ft_printerr/ft_handle_point.c \
	src/aux/ft_printerr/ft_printerror.c \
	src/aux/ft_printerr/ft_printf.c \
	src/aux/ft_printerr/ft_putchar_fd.c \
	src/aux/ft_printerr/ft_putdecimal_int.c \
	src/aux/ft_printerr/ft_putnbr_fd.c \
	src/aux/ft_printerr/ft_putstr_fd.c

SRC_BUILTIN = \
	src/built-in/cd/cd.c \
	src/built-in/cd/create_entry.c \
	src/built-in/echo/echo.c \
	src/built-in/envars/envars.c \
	src/built-in/envars/find_envars.c \
	src/built-in/envars/init_envars.c \
	src/built-in/exit/exit.c \
	src/built-in/exports/add_update.c \
	src/built-in/exports/exports_parsing.c \
	src/built-in/exports/exports.c \
	src/built-in/exports/init_exports.c \
	src/built-in/pwd/pwd.c \
	src/built-in/unset/unset.c

SRC_ERROR = \
	src/error/err_code.c

SRC_EXECUTION = \
	src/execution/aux.c \
	src/execution/err_handler.c \
	src/execution/exec_builtin.c \
	src/execution/execution.c \
	src/execution/paths.c \
	src/execution/pipe_aux.c \
	src/execution/pipe.c \
	src/execution/exec_in_parent.c

SRC_EXIT_FREE = \
	src/exit_free/exit_free.c \
	src/exit_free/free_contents.c \
	src/exit_free/ft_free.c

SRC_HDOCS = \
	src/hdocs/hdocs.c

SRC_PARCING = \
	src/parcing/parcing.c \
	src/parcing/checkunclosedquotes.c \
	src/parcing/ft_split_espace.c \
	src/parcing/split_checkers.c \
	src/parcing/tokenschecker.c \
	src/parcing/removequotes.c \
	src/parcing/list_funcs.c \
	src/parcing/checkforexpansion.c \
	src/parcing/preparelist.c \
	src/parcing/expansion.c

SRCS = \
	$(SRC_MAIN) \
	$(SRC_ARG_PARSER) \
	$(SRC_AUX) \
	$(SRC_BUILTIN) \
	$(SRC_ERROR) \
	$(SRC_EXECUTION) \
	$(SRC_EXIT_FREE) \
	$(SRC_HDOCS) \
	$(SRC_PARCING)

# ─── Objects & deps (mirror src/ tree under obj/) ───────────────────────────

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

# ─── Rules ──────────────────────────────────────────────────────────────────

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compiled $(NAME)"

# Compile each .c → obj/<path>/<file>.o and generate a .d dependency file
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re