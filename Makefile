# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 22:19:53 by fvon-der          #+#    #+#              #
#    Updated: 2025/02/25 19:22:31 by fvon-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET_COLOR = \033[0m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
GREEN       = \033[1;32m
RED         = \033[1;31m

# Project names
NAME        = fdf
NAME_DEBUG  = fdf_debug

# Directories
OBJ_DIR     = obj/fdf
SRC_DIR     = src/fdf
LIB42_DIR   = lib/lib42
MLX_DIR     = lib/mlx
INCLUDE_DIR = include

# Include paths for libraries and headers
INCLUDE     = -I$(INCLUDE_DIR) -I$(LIB42_DIR)/libft/include -I$(LIB42_DIR)/ft_printf/include -I$(LIB42_DIR)/gnl/include -I$(MLX_DIR)/include/MLX42

# Compiler, rm command, and flags
CC          = cc
MAKE        = make
RM          = rm -f
FLAGS       = -Wall -Wextra -Werror -Wunused $(INCLUDE)

# Debug flags
DEBUG_FLAGS  = -Wall -Wextra $(INCLUDE) -g -O0 -fsanitize=undefined \
               -fno-strict-aliasing -fno-omit-frame-pointer -fstack-protector -DDEBUG -fno-inline

# Libraries to link with
LIBRARIES    = -L$(LIB42_DIR) -l42 -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  # macOS specifics can be adjusted

# Source and Object files
SRC          = $(SRC_DIR)/camera.c \
               $(SRC_DIR)/event_handler.c \
               $(SRC_DIR)/renderer.c \
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
               $(SRC_DIR)/transformation.c \
               $(SRC_DIR)/color_utils.c \
               $(SRC_DIR)/debug_utils.c \
               $(SRC_DIR)/events.c \
               $(SRC_DIR)/mlx_events.c \
               $(SRC_DIR)/mlx_mouse_events.c \
               $(SRC_DIR)/projection.c \
               $(SRC_DIR)/rotation.c
OBJ          = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target: build
all: | $(OBJ_DIR) $(LIB42_DIR) $(MLX_DIR) $(NAME)

# Ensure the object directory exists
$(OBJ_DIR):
	@echo "$(YELLOW)Creating directory: $(OBJ_DIR)$(RESET_COLOR)"
	@mkdir -p $(OBJ_DIR)

# Build lib42 if not present
$(LIB42_DIR):
	@echo "$(YELLOW)Downloading and building lib42...$(RESET_COLOR)"
	@mkdir -p $(LIB42_DIR)
	@git clone https://github.com/F-vdHaar/42_lib.git $(LIB42_DIR) || echo "$(RED)Failed to clone lib42 repository.$(RESET_COLOR)"
	@$(MAKE) -C $(LIB42_DIR)

# Build MLX if not present
$(MLX_DIR):
	@echo "$(YELLOW)Downloading and building MLX...$(RESET_COLOR)"
	@mkdir -p $(MLX_DIR)
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) || echo "$(RED)Failed to clone MLX42 repository.$(RESET_COLOR)"
	@$(MAKE) -C $(MLX_DIR)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(LIB42_DIR) $(MLX_DIR)
	@echo "$(GREEN)Compiling fdf object: $<$(RESET_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

# Link the final executable
$(NAME): $(OBJ) $(LIB42_DIR)/lib42.a $(MLX_DIR)/libmlx.a
	@echo "$(BLUE)Linking $(NAME)$(RESET_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBRARIES)
	@echo "$(GREEN)$(NAME) built successfully.$(RESET_COLOR)"

# Clean object files
clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET_COLOR)"
	@$(RM) $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files cleaned.$(RESET_COLOR)"

# Clean everything (executables and libraries)
fclean: clean
	@echo "$(RED)Cleaning executables and libraries...$(RESET_COLOR)"
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIB42_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(GREEN)All files cleaned.$(RESET_COLOR)"

# Rebuild everything
re: fclean all

# Norm checking
norm:
	@echo "$(BLUE)Running Norminette...$(RESET_COLOR)"
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep -v 'OK!' || true
	@echo "$(GREEN)Norminette check complete.$(RESET_COLOR)"

.PHONY: all clean fclean re norm
