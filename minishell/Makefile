# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 12:36:11 by msimoes           #+#    #+#              #
#    Updated: 2026/02/12 14:18:59 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = minishell

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRC_FILES = main.c history.c

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

$(ARG_PARSER_LIB):
	@$(MAKE) -C src/arg_parser

# Build aux static lib
$(AUX_LIB):
	@$(MAKE) -C src/aux

# Build builtin static lib
$(BUILTIN_LIB):
	@$(MAKE) -C src/built-in

# Build error static lib
$(ERROR_LIB):
	@$(MAKE) -C src/error

$(EXECUTION_LIB):
	@$(MAKE) -C src/execution

$(EXIT_FREE_LIB):
	@$(MAKE) -C src/exit_free

$(HDOCS_LIB):
	@$(MAKE) -C src/hdocs

$(PARCING_LIB):
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
	rm -f $(NAME)
	rm -f $(AUX_LIB)
	rm -f $(FULL_LIBS)
	@echo "Fully cleaned."

re: fclean all

.PHONY: all clean fclean re $(FULL_LIBS)