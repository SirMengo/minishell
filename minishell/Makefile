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
AUX_LIB     = src/aux/lib_aux.a
BUILTIN_LIB = src/built-in/lib_builtin.a
PARCING_LIB = src/parcing/parcing.a

# Compiler and flags
CCFLAGS  = cc -Wall -Wextra -Werror -g
LDFLAGS  = -lreadline -lncurses
INCLUDES = -Isrc/aux -Isrc/execution -Isrc/parcing

all: $(NAME)

# Link the executable
$(NAME): $(OBJ) $(AUX_LIB) $(BUILTIN_LIB) $(PARCING_LIB)
	$(CCFLAGS) $(OBJ) $(BUILTIN_LIB) $(PARCING_LIB) $(AUX_LIB) $(LDFLAGS) -o $(NAME)
	@echo "Compiled $(NAME)"

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CCFLAGS) $(INCLUDES) -c $< -o $@

# Build aux static lib
$(AUX_LIB):
	@$(MAKE) -C src/aux

# Build builtin static lib
$(BUILTIN_LIB):
	@$(MAKE) -C src/built-in

# Build parcing static lib
$(PARCING_LIB):
	@$(MAKE) -C src/parcing

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C src/aux clean
	$(MAKE) -C src/execution clean
	$(MAKE) -C src/parcing clean

fclean: clean
	rm -f $(NAME)
	rm -f $(AUX_LIB)
	rm -f $(BUILTIN_LIB)
	rm -f $(PARCING_LIB)
	@echo "Fully cleaned."

re: fclean all

.PHONY: all clean fclean re