# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 22:19:53 by fvon-der          #+#    #+#              #
#    Updated: 2025/01/11 17:17:11 by fvon-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project names
NAME		= fdf

# Compiler and flags
CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror
MAKE		= make

# Colors
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m
RESET		= \033[0m

# Directories
OBJ_DIR     = obj/fdf
SRC_DIR     = src/fdf
LIBFT_DIR   = lib/libft
PRINTF_DIR  = lib/ft_printf
GNL_DIR  = lib/gnl
MLX_DIR		= lib/mlx
INCLUDE_DIR = include

# Include paths for libraries and headers
INCLUDE     = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(PRINTF_DIR)/include  -I$(GNL_DIR)/include  -I$(MLX_DIR)

# Libraries to link with
LIBRARIES   = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(GNL_DIR) -L$(MLX_DIR) -lft -lftprintf -lmlx -framework OpenGL -framework AppKit

# Source and Object files
SRC			= $(SRC_DIR)/camera.c \
			$(SRC_DIR)/event_handler.c \
			$(SRC_DIR)/fdf_test_utils.c \
			$(SRC_DIR)/key_handler.c \
			$(SRC_DIR)/map.c \
			$(SRC_DIR)/mouse_handler.c \
			$(SRC_DIR)/transformation_utils.c \
			$(SRC_DIR)/draw.c \
			$(SRC_DIR)/fdf.c \
			$(SRC_DIR)/fdf_utils.c \
			$(SRC_DIR)/line.c \
			$(SRC_DIR)/map_utils.c \
			$(SRC_DIR)/transformation.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
all: | $(OBJ_DIR) $(NAME)

# Ensure directories exist
$(OBJ_DIR):
	@echo "Creating directory: $(OBJ_DIR)"
	@mkdir -p $(OBJ_DIR)

# Ensure libraries are built if they don’t exist
$(LIBFT_DIR)/libft.a:
	@echo "$(CYAN)Checking for libft library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a: $(LIBFT_DIR)/libft.a
	@echo "$(CYAN)Checking for ft_printf library...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL_DIR)/libgnl.a: $(LIBFT_DIR)/libft.a
	@echo "$(CYAN)Checking for GNL library...$(RESET)"
	@$(MAKE) -C $(GNL_DIR)

$(MLX_DIR)/libmlx.a:
	@echo "$(CYAN)Checking for mlx library...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(MLX_DIR)/libmlx.a
	@echo "Compiling fdf object: $<"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "Object file created: $@"

# Link the final executable
$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(MLX_DIR)/libmlx.a
	@echo "Linking $(NAME) with libft.a, ft_printf.a, and mlx"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBRARIES)
	@echo "$(NAME) built successfully."

# Clean object files
clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@echo "Object files cleaned."

# Clean all files
fclean: clean
	@echo "Cleaning executable and libraries..."
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "All files cleaned."

# Rebuild everything
re: fclean all
	@echo "Rebuilding everything..."

.PHONY: all clean fclean re
