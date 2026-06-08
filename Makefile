# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 19:08:22 by canoduran         #+#    #+#              #
#    Updated: 2026/06/08 21:12:06 by canoduran        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- COLORS ---
RED      = \033[0;31m
BLUE     = \033[0;34m
GREEN    = \033[0;32m
RESET    = \033[0m

# --- VARIABLES ---
OS = $(shell uname)
CC       = cc
NAME     = cub3d
CFLAGS   = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

# --- DIRECTORIES ---
DIR_SRC     = src
DIR_CORE    = $(DIR_SRC)/core
OBJ_DIR     = obj

# --- SOURCES ---
SRC = $(DIR_CORE)/main.c 

# --- OBJECTS ---
OBJ = $(SRC:.c=.o)

# --------------------------------------------------------
#        BARRE DE PROGRESSION (ROSE) POUR COMPILATION
# --------------------------------------------------------

NB := $(words $(OBJ))
BARLEN = 30
COUNTER = 0

%.o: %.c
	@$(eval COUNTER := $(shell echo $$(($(COUNTER) + 1))))
	@$(eval PROG := $(shell echo $$(($(COUNTER) * 100 / $(NB))) ))
	@$(eval FILLED := $(shell echo $$(($(PROG) * $(BARLEN) / 100)) ))
	@$(eval EMPTY := $(shell echo $$(($(BARLEN) - $(FILLED))) ))
	@printf "\r\033[35m[%s%s] %3s%%\033[0m  \033[90m%-40s\033[0m" \
		$$(printf '#%.0s' $$(seq 1 $(FILLED))) \
		$$(printf '.%.0s' $$(seq 1 $(EMPTY))) \
		"$(PROG)" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------------------


# --- RULES ---
all : $(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)

clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@rm -f $(OBJ)
	@make -s clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@printf "$(RED)Removing executable $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR) --no-print-directory

re : fclean all

.PHONY : all clean fclean re