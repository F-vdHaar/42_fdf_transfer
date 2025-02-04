# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 23:04:51 by fvon-de           #+#    #+#              #
#    Updated: 2025/02/04 00:04:43 by fvon-de          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for output
RESET_COLOR	= \033[0m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
GREEN		= \033[1;32m
RED			= \033[1;31m

# Project settings
NAME		= lib42.a
INCLUDE		= include
LIBFT_INC	= $(LIBFT_DIR)/include
GNL_INC		= $(GNL_DIR)/include
PRINTF_INC	= $(PRINTF_DIR)/include
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wunused \
			  -I$(INCLUDE) -I$(LIBFT_INC) -I$(GNL_INC) -I$(PRINTF_INC)
DEBUG_FLAGS = $(CFLAGS) -g -O0 -fsanitize=address -fsanitize=undefined \
			  -fno-strict-aliasing -fno-omit-frame-pointer -fstack-protector -DDEBUG -fno-inline
AR			= ar rcs

# Directories
LIBFT_DIR	= libft
GNL_DIR		= gnl
PRINTF_DIR	= ft_printf

# Version settings (default to v1)
LIBFT_VERSION  ?= v1
GNL_VERSION    ?= v1
PRINTF_VERSION ?= v1

# Source files
LIBFT_SRC	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			  ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			  ft_tolower.c ft_toupper.c ft_lstadd_back_bonus.c \
			  ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			  ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
			  ft_lstnew_bonus.c ft_lstsize_bonus.c

GNL_SRC		= get_next_line.c get_next_line_utils.c \
			  get_next_line_bonus.c get_next_line_utils_bonus.c

PRINTF_SRC	= ft_flags.c ft_print_char.c ft_print_flag.c ft_print_hex.c \
			  ft_print_str.c ft_flags_utils.c ft_printf.c ft_printf_utoa.c \
			  ft_print_int.c ft_print_unsigned.c ft_nbr_len.c ft_printf_itoa.c \
			  ft_printf_xtoa.c ft_print_ptr.c

# Define object files
LIBFT_OBJS		= $(LIBFT_SRC:%.c=$(LIBFT_DIR)/obj/$(LIBFT_VERSION)/%.o)
GNL_OBJS		= $(GNL_SRC:%.c=$(GNL_DIR)/obj/$(GNL_VERSION)/%.o)
PRINTF_OBJS		= $(PRINTF_SRC:%.c=$(PRINTF_DIR)/obj/$(PRINTF_VERSION)/%.o)
OBJS			= $(LIBFT_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# Debug object files
LIBFT_DEBUG_OBJS	= $(LIBFT_SRC:%.c=$(LIBFT_DIR)/obj/$(LIBFT_VERSION)/debug_%.o)
GNL_DEBUG_OBJS		= $(GNL_SRC:%.c=$(GNL_DIR)/obj/$(GNL_VERSION)/debug_%.o)
PRINTF_DEBUG_OBJS	= $(PRINTF_SRC:%.c=$(PRINTF_DIR)/obj/$(PRINTF_VERSION)/debug_%.o)
DEBUG_OBJS			= $(LIBFT_DEBUG_OBJS) $(GNL_DEBUG_OBJS) $(PRINTF_DEBUG_OBJS)

# Default rule to build
all: $(NAME)

# Debug build target
debug: $(DEBUG_OBJS)
	@echo "$(YELLOW)Creating debug library...$(RESET_COLOR)"
	@$(AR) libdebug.a $(DEBUG_OBJS)
	@echo "$(GREEN)Debug library created!$(RESET_COLOR)"

# Ensure object directories exist
$(LIBFT_DIR)/obj/$(LIBFT_VERSION) $(GNL_DIR)/obj/$(GNL_VERSION) $(PRINTF_DIR)/obj/$(PRINTF_VERSION):
	@mkdir -p $@

# Build rule for library
$(NAME): $(OBJS) libft_done gnl_done printf_done
	@echo "$(YELLOW)Creating library $(NAME)...$(RESET_COLOR)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(NAME) created successfully!$(RESET_COLOR)"

# Rules for building normal object files
$(LIBFT_DIR)/obj/$(LIBFT_VERSION)/%.o: $(LIBFT_DIR)/src/$(LIBFT_VERSION)/%.c | $(LIBFT_DIR)/obj/$(LIBFT_VERSION)
	@echo "$(YELLOW)Compiling LIBFT: $< to $@...$(RESET_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

libft_done: $(LIBFT_OBJS)
	@echo "$(GREEN)LIBFT compilation complete!$(RESET_COLOR)"

$(GNL_DIR)/obj/$(GNL_VERSION)/%.o: $(GNL_DIR)/src/$(GNL_VERSION)/%.c | $(GNL_DIR)/obj/$(GNL_VERSION)
	@echo "$(YELLOW)Compiling GNL: $< to $@...$(RESET_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

gnl_done: $(GNL_OBJS)
	@echo "$(GREEN)GNL compilation complete!$(RESET_COLOR)"

$(PRINTF_DIR)/obj/$(PRINTF_VERSION)/%.o: $(PRINTF_DIR)/src/$(PRINTF_VERSION)/%.c | $(PRINTF_DIR)/obj/$(PRINTF_VERSION)
	@echo "$(YELLOW)Compiling PRINTF: $< to $@...$(RESET_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

printf_done: $(PRINTF_OBJS)
	@echo "$(GREEN)PRINTF compilation complete!$(RESET_COLOR)"

# Rules for building debug object files
$(LIBFT_DIR)/obj/$(LIBFT_VERSION)/debug_%.o: $(LIBFT_DIR)/src/$(LIBFT_VERSION)/%.c | $(LIBFT_DIR)/obj/$(LIBFT_VERSION)
	@echo "$(YELLOW)Compiling LIBFT debug: $< to $@...$(RESET_COLOR)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

$(GNL_DIR)/obj/$(GNL_VERSION)/debug_%.o: $(GNL_DIR)/src/$(GNL_VERSION)/%.c | $(GNL_DIR)/obj/$(GNL_VERSION)
	@echo "$(YELLOW)Compiling GNL debug: $< to $@...$(RESET_COLOR)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

$(PRINTF_DIR)/obj/$(PRINTF_VERSION)/debug_%.o: $(PRINTF_DIR)/src/$(PRINTF_VERSION)/%.c | $(PRINTF_DIR)/obj/$(PRINTF_VERSION)
	@echo "$(YELLOW)Compiling PRINTF debug: $< to $@...$(RESET_COLOR)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

# Bonus target (if needed)
bonus: all

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET_COLOR)"
	@rm -rf $(LIBFT_DIR)/obj $(GNL_DIR)/obj $(PRINTF_DIR)/obj

# Clean everything
fclean: clean
	@echo "$(RED)Removing libraries...$(RESET_COLOR)"
	@rm -f $(NAME) libdebug.a

# Rebuild everything
re: fclean all

# Norminette target
norm:
	@echo "$(BLUE)Running Norminette...$(RESET_COLOR)"
	@norminette $(SRC_FILES) | grep -v 'OK!' || true
	@echo "$(GREEN)Norminette check complete!$(RESET_COLOR)"

# Phony Targets
.PHONY: all clean fclean re norm debug bonus libft_done gnl_done printf_done
