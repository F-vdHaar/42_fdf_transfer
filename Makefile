# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 22:19:53 by fvon-der          #+#    #+#              #
#    Updated: 2025/02/24 17:50:50 by fvon-de          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET_COLOR	= \033[0m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
GREEN		= \033[1;32m
RED			= \033[1;31m

# Project names
NAME		= fdf
NAME_LINUX	= fdf_linux

# Directories
OBJ_DIR     = obj/fdf
SRC_DIR     = src/fdf
LIB42_DIR   = lib/lib42
# MLX directories for each platform
MLX_MAC_DIR     = lib/mlx
MLX_LINUX_DIR   = lib/minilibx-linux
# Default MLX_DIR for macOS builds; overridden for Linux targets.
MLX_DIR   = $(MLX_MAC_DIR)
INCLUDE_DIR = include

# Include paths for libraries and headers
INCLUDE     = -I$(INCLUDE_DIR) -I$(LIB42_DIR)/libft/include -I$(LIB42_DIR)/ft_printf/include -I$(LIB42_DIR)/gnl/include -I$(MLX_DIR)

# Compiler, rm command, and flags
CC			= cc
MAKE		= make
RM          = rm -f
FLAGS		= -Wall -Wextra -Werror -Wunused $(INCLUDE)

# Debug flags (include symbols and sanitizers)
#-fsanitize=address comment this out when using valgrind
DEBUG_FLAGS =-Wall -Wextra  $(INCLUDE) -g -O0   -fsanitize=undefined \
			  -fno-strict-aliasing -fno-omit-frame-pointer -fstack-protector -DDEBUG -fno-inline

# Libraries to link with (macOS)
LIBRARIES_MAC   = -L$(LIB42_DIR) -L$(MLX_MAC_DIR) -l42 -lmlx -framework OpenGL -framework AppKit

# Libraries to link with (Linux)
LIBRARIES_LINUX = -L$(MLX_LINUX_DIR) -lmlx -L$(LIB42_DIR) -l42 -lX11 -lXext -lm -ldl

# Source and Object files
SRC			= $(SRC_DIR)/camera.c \
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
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEBUG_OBJ	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/debug_%.o)

# Default target: build using macOS MLX
all: | $(OBJ_DIR) $(NAME)

# Linux release target
linux: export MLX_DIR=$(MLX_LINUX_DIR)
linux: | $(OBJ_DIR) $(NAME_LINUX)

# Linux debug target using debug flags and a distinct executable name
linux_debug: export MLX_DIR=$(MLX_LINUX_DIR)
linux_debug: | $(OBJ_DIR)
	@echo "$(BLUE)Compiling debug objects for Linux...$(RESET_COLOR)"
	@$(MAKE) $(DEBUG_OBJ)
	@echo "$(BLUE)Linking debug version for Linux$(RESET_COLOR)"
	@$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJ) -o fdf_linux_debug $(LIBRARIES_LINUX)
	@echo "$(GREEN)Linux debug version built successfully as fdf_linux_debug.$(RESET_COLOR)"

# Debug target for macOS (if needed)
debug: | $(OBJ_DIR) fdf_debug

fdf_debug: $(DEBUG_OBJ) $(LIB42_DIR)/lib42.a $(MLX_MAC_DIR)/libmlx.a
	@echo "$(BLUE)Linking debug version of $(NAME) for macOS$(RESET_COLOR)"
	@$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJ) -o fdf_debug $(LIBRARIES_MAC)
	@echo "$(GREEN)Debug version of $(NAME) built successfully.$(RESET_COLOR)"

# Valgrind target (uses the macOS build by default)
valgrind: $(NAME)
	@echo "$(BLUE)Running Valgrind...$(RESET_COLOR)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Ensure the object directory exists
$(OBJ_DIR):
	@echo "$(YELLOW)Creating directory: $(OBJ_DIR)$(RESET_COLOR)"
	@mkdir -p $(OBJ_DIR)

# Build external libraries if needed
$(LIB42_DIR)/lib42.a:
	@echo "$(YELLOW)Checking for lib42 library...$(RESET_COLOR)"
	@$(MAKE) -C $(LIB42_DIR)

$(MLX_MAC_DIR)/libmlx.a:
	@echo "$(YELLOW)Checking for mlx (macOS) library...$(RESET_COLOR)"
	@$(MAKE) -C $(MLX_MAC_DIR)

$(MLX_LINUX_DIR)/libmlx.a:
	@echo "$(YELLOW)Checking for mlx (Linux) library...$(RESET_COLOR)"
	@$(MAKE) -C $(MLX_LINUX_DIR)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling fdf object: $<$(RESET_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

# Compile source files into debug object files
$(OBJ_DIR)/debug_%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling fdf debug object: $<$(RESET_COLOR)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

# Link the final executable for macOS
$(NAME): $(OBJ) $(LIB42_DIR)/lib42.a $(MLX_MAC_DIR)/libmlx.a
	@echo "$(BLUE)Linking $(NAME) for macOS$(RESET_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBRARIES_MAC)
	@echo "$(GREEN)$(NAME) built successfully for macOS.$(RESET_COLOR)"

# Link the final executable for Linux
$(NAME_LINUX): $(OBJ) $(LIB42_DIR)/lib42.a $(MLX_LINUX_DIR)/libmlx.a
	@echo "$(BLUE)Linking $(NAME_LINUX) for Linux$(RESET_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME_LINUX) $(LIBRARIES_LINUX)
	@echo "$(GREEN)$(NAME_LINUX) built successfully for Linux.$(RESET_COLOR)"

# Clean object files
clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET_COLOR)"
	@$(RM) $(OBJ) $(DEBUG_OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files cleaned.$(RESET_COLOR)"

# Clean everything (executables and libraries)
fclean: clean
	@echo "$(RED)Cleaning executables and libraries...$(RESET_COLOR)"
	@$(RM) $(NAME) $(NAME_LINUX) fdf_debug fdf_linux_debug
	@$(MAKE) fclean -C $(LIB42_DIR)
	@$(MAKE) clean -C $(MLX_MAC_DIR)
	@$(MAKE) clean -C $(MLX_LINUX_DIR)
	@echo "$(GREEN)All files cleaned.$(RESET_COLOR)"

# Rebuild everything
re: fclean all

# Norm checking
norm:
	@echo "$(BLUE)Running Norminette...$(RESET_COLOR)"
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep -v 'OK!' || true
	@echo "$(GREEN)Norminette check complete.$(RESET_COLOR)"

.PHONY: all linux linux_debug debug fdf_debug valgrind clean fclean re norm
