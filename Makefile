# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 22:19:53 by fvon-der          #+#    #+#              #
#    Updated: 2024/07/01 22:21:22 by fvon-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -Iinclude -Ilib/libft/include -Ilib/ft_printf/include
LDFLAGS     = -Llib/libft -lft -Llib/ft_printf -lftprintf
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = lib/libft
LIBFTPRINTF_DIR = lib/ft_printf
RM          = rm -f

# Source and Object files
SRC         = $(wildcard $(SRC_DIR)/*.c)
OBJ         = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Targets
all: $(OBJ_DIR) $(LIBFT_DIR)/libft.a $(LIBFTPRINTF_DIR)/libftprintf.a my_program

# Create object directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Build libftprintf
$(LIBFTPRINTF_DIR)/libftprintf.a: $(LIBFT_DIR)/libft.a
	@$(MAKE) -C $(LIBFTPRINTF_DIR)

# Link the final executable
my_program: $(OBJ)
	@echo "Linking: $@"
	@$(CC) $(OBJ) $(LDFLAGS) -o $@

# Clean object files and libraries
clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@echo "Cleaned all object files and libraries!"

# Clean all
fclean: clean
	@$(RM) -f my_program
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@echo "Cleaned all!"

# Rebuild
re: fclean all

.PHONY: all clean fclean re
