# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 11:15:56 by msimoes           #+#    #+#              #
#    Updated: 2025/11/07 11:17:16 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = minishell

# Directories
SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c history.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

AUX_LIB = src/aux/lib_aux.a
<<<<<<< HEAD
PARCING_LIB = src/parcing/parcing.a

=======
BUILTIN_LIB = src/execution/lib_builtin.a
>>>>>>> execution

# Compiler and flags
CCFLAGS =cc -Wall -Wextra -Werror -g
LDFLAGS = -lreadline -lncurses
INCLUDES = -Isrc/aux -Isrc/execution

all: $(NAME)

# Link the executable
<<<<<<< HEAD
$(NAME): $(OBJ) $(PARCING_LIB) $(AUX_LIB)
	$(CCFLAGS) $(OBJ) $(PARCING_LIB) $(AUX_LIB) $(LDFLAGS) -o $(NAME)
=======
$(NAME): $(OBJ) $(AUX_LIB) $(BUILTIN_LIB)
	$(CCFLAGS) $(OBJ) $(AUX_LIB) $(BUILTIN_LIB) $(LDFLAGS) -o $(NAME)
>>>>>>> execution
	@echo "Compiled $(NAME)"

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CCFLAGS) $(INCLUDES) -c $< -o $@

# Build aux static lib
$(AUX_LIB):
	@$(MAKE) -C src/aux

<<<<<<< HEAD
# Build parcing lib
$(PARCING_LIB):
	@$(MAKE) -C src/parcing
=======
$(BUILTIN_LIB)
	@$(MAKE) -C src/execution
>>>>>>> execution

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C src/aux clean
	$(MAKE) -C src/parcing clean

fclean: clean
	rm -f $(NAME)
	rm -f $(AUX_LIB)
<<<<<<< HEAD
	rm -f $(PARCING_LIB)
=======
	rm -f $(BUILTIN_LIB)
>>>>>>> execution
	@echo "Fully cleaned."

re: fclean all

.PHONY: all clean fclean re

