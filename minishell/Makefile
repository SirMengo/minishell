# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 12:36:11 by msimoes           #+#    #+#              #
#    Updated: 2026/02/23 15:09:28 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = minishell

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRC_FILES = main.c history.c signal.c signal_toggle.c

# Object files
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Static libraries
ARG_PARSER_LIB = src/arg_parser/arg_parser.a
AUX_LIB = src/aux/lib_aux.a
BUILTIN_LIB = src/built-in/lib_builtin.a
ERROR_LIB = src/error/err_code.a
EXECUTION_LIB = src/execution/execution.a
EXIT_FREE_LIB = src/exit_free/exit_free.a
HDOCS_LIB = src/hdocs/hdocs.a
PARCING_LIB = src/parcing/parcing.a
FULL_LIBS = $(ARG_PARSER_LIB) $(EXECUTION_LIB) $(EXIT_FREE_LIB) $(HDOCS_LIB) \
			$(PARCING_LIB) $(BUILTIN_LIB) $(ERROR_LIB) $(AUX_LIB)

# Compiler and flags
CCFLAGS  = cc -Wall -Wextra -Werror -g
LDFLAGS  = -lreadline -lncurses
INCLUDES = -Isrc/aux -Isrc/execution -Isrc/parcing

all: $(NAME)

# Link the executable
$(NAME): $(OBJ) $(FULL_LIBS)
	$(CCFLAGS) $(OBJ) $(FULL_LIBS) $(LDFLAGS) -o $(NAME)
	@echo "Compiled $(NAME)"

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CCFLAGS) $(INCLUDES) -c $< -o $@

# Define all source files for each library
ARG_PARSER_SRCS = src/arg_parser/arg_parser.c src/arg_parser/aux.c 	src/arg_parser/open_close.c
AUX_SRCS = src/aux/ft_calloc.c src/aux/ft_split.c src/aux/ft_strdup.c src/aux/ft_substr.c \
	src/aux/ft_strlen.c src/aux/ft_strjoin.c src/aux/lst_init.c src/aux/ft_strcmp.c \
	src/aux/ft_findchar.c src/aux/ft_list_funcs.c src/aux/ft_isalpha.c src/aux/ft_isalnum.c \
	src/aux/get_list.c src/aux/ft_atoi.c src/aux/ft_itoa.c src/aux/ft_memset.c \
	src/aux/ft_strchr.c src/aux/arr_size.c src/aux/ft_lstsize.c src/aux/ft_strnstr.c \
	src/aux/ft_isnum.c src/aux/ft_printerr/ft_handle_hex.c src/aux/ft_printerr/ft_handle_point.c \
	src/aux/ft_printerr/ft_printerror.c src/aux/ft_printerr/ft_printf.c src/aux/ft_printerr/ft_putchar_fd.c \
	src/aux/ft_printerr/ft_putdecimal_int.c src/aux/ft_printerr/ft_putnbr_fd.c src/aux/ft_printerr/ft_putstr_fd.c

BUILTIN_SRCS = src/built-in/cd/cd.c src/built-in/cd/create_entry.c src/built-in/echo/echo.c \
	src/built-in/envars/envars.c src/built-in/envars/find_envars.c src/built-in/envars/init_envars.c \
	src/built-in/exit/exit.c src/built-in/exports/add_update.c src/built-in/exports/exports_parsing.c \
	src/built-in/exports/exports.c src/built-in/exports/init_exports.c src/built-in/pwd/pwd.c \
	src/built-in/unset/unset.c

ERROR_SRCS = src/error/err_code.c
EXECUTION_SRCS = src/execution/aux.c src/execution/err_handler.c src/execution/exec_builtin.c \
	src/execution/execution.c src/execution/paths.c src/execution/pipe_aux.c src/execution/pipe.c \
	src/execution/exec_in_parent.c

EXIT_FREE_SRCS = src/exit_free/exit_free.c src/exit_free/free_contents.c src/exit_free/ft_free.c
HDOCS_SRCS = src/hdocs/hdocs.c
PARCING_SRCS = src/parcing/parcing.c src/parcing/checkunclosedquotes.c src/parcing/ft_split_espace.c \
	src/parcing/split_checkers.c src/parcing/tokenschecker.c src/parcing/removequotes.c \
	src/parcing/list_funcs.c src/parcing/checkforexpansion.c src/parcing/preparelist.c \
	src/parcing/expansion.c

# Library rules with dependencies
$(ARG_PARSER_LIB): $(ARG_PARSER_SRCS)
	@$(MAKE) -C src/arg_parser

$(AUX_LIB): $(AUX_SRCS)
	@$(MAKE) -C src/aux

$(BUILTIN_LIB): $(BUILTIN_SRCS)
	@$(MAKE) -C src/built-in

$(ERROR_LIB): $(ERROR_SRCS)
	@$(MAKE) -C src/error

$(EXECUTION_LIB): $(EXECUTION_SRCS)
	@$(MAKE) -C src/execution

$(EXIT_FREE_LIB): $(EXIT_FREE_SRCS)
	@$(MAKE) -C src/exit_free

$(HDOCS_LIB): $(HDOCS_SRCS)
	@$(MAKE) -C src/hdocs

$(PARCING_LIB): $(PARCING_SRCS)
	@$(MAKE) -C src/parcing

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C src/arg_parser clean
	$(MAKE) -C src/aux clean
	$(MAKE) -C src/built-in clean
	$(MAKE) -C src/error clean
	$(MAKE) -C src/execution clean
	$(MAKE) -C src/exit_free clean
	$(MAKE) -C src/hdocs clean
	$(MAKE) -C src/parcing clean

fclean: clean
	$(MAKE) -C src/arg_parser fclean
	$(MAKE) -C src/aux fclean
	$(MAKE) -C src/built-in fclean
	$(MAKE) -C src/error fclean
	$(MAKE) -C src/execution fclean
	$(MAKE) -C src/exit_free fclean
	$(MAKE) -C src/hdocs fclean
	$(MAKE) -C src/parcing fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re