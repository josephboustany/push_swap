# Compiler and archiver settings
CC := cc
AR := ar rcs
CFLAGS := -Wall -Wextra -Werror

# Project and library name
PROJECT := "Push_Swap Project"
AUTHOR := "Joseph Boustany"
NAME := push_swap

# Source files
SRCS := main.c \
	basic_operations.c \
	linked_list.c \
	list_initialization.c \
	rotation_operations.c \
	utils.c \
	radix_sort.c

# Object files
OBJS := $(SRCS:.c=.o)

# Path to the libft library
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

# ANSI color codes
GREEN := \033[0;32m
RESET := \033[0m

# Title function
define title
	@echo "=========================================================================================="
	@echo "$(GREEN)                  		$(PROJECT)$(RESET)"
	@echo "                                   $(AUTHOR)"
	@echo "=========================================================================================="
endef

# Message function for consistent formatting
define message
	@echo "=================================================="
	@echo "$(GREEN)  $(1)$(RESET)"
	@echo "=================================================="
endef

# Default target
all: title $(NAME)

# Title target
title:
	$(title)

# Main target
$(NAME): $(LIBFT) $(OBJS)
	$(call message,"Creating executable $(NAME)...")
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	$(call message,"Executable $(NAME) created successfully.")

# Compile libft
$(LIBFT):
	$(call message,"Compiling libft...")
	@$(MAKE) -C $(LIBFT_DIR)
	$(call message,"libft compiled successfully.")

# Pattern rule for object files
%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Clean up object files
clean:
	$(call message,"Cleaning object files...")
	@rm -f $(OBJS)
	$(call message,"Object files cleaned.")
	$(call message,"Cleaning libft...")
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(call message,"libft cleaned.")

# Full clean up
fclean: clean
	$(call message,"Removing executable $(NAME)...")
	@rm -f $(NAME)
	$(call message,"Executable $(NAME) removed.")
	$(call message,"Full cleaning libft...")
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(call message,"Full libft cleaning done.")

# Rebuild everything
re: fclean all

# Declare targets that are not files
.PHONY: all clean fclean re bonus title
