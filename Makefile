# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 18:24:35 by pucci17pink       #+#    #+#              #
#    Updated: 2026/07/06 15:48:34 by pucci17pink      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --- COLORS ---
RED      = \033[0;31m
BLUE     = \033[0;34m
GREEN    = \033[0;32m
RESET    = \033[0m

# --- VARIABLES ---
OS        = $(shell uname)
CC        = cc
NAME      = cub3d
CFLAGS    = -Wall -Wextra -Werror -I$(MLX42_DIR)/include
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
GNL_DIR   = get-next-line
MLX42_DIR = MLX42
MLX42     = $(MLX42_DIR)/build/libmlx42.a

# --- DIRECTORIES ---
DIR_SRC     = src
DIR_MAP     = $(DIR_SRC)/map
DIR_PARSING = $(DIR_SRC)/parsing
OBJ_DIR     = obj

# --- SOURCES ---
SRC = $(DIR_SRC)/main.c \
      $(DIR_SRC)/render/render.c \
      $(DIR_SRC)/render/init_game.c \
      $(DIR_SRC)/render/minimap.c \
      $(DIR_MAP)/check_filename.c \
      $(DIR_MAP)/take_map.c \
      $(DIR_SRC)/init.c \
      $(DIR_PARSING)/parsing.c \
      $(DIR_PARSING)/utils.c \
      $(GNL_DIR)/get_next_line.c \
      $(GNL_DIR)/get_next_line_utils.c

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

# --- RULES ---
all : $(LIBFT) $(MLX42) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR) --no-print-directory

$(MLX42):
	@cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
	@make -C $(MLX42_DIR)/build -j4 --no-print-directory

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -lglfw -lm -o $(NAME)

clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@rm -f $(OBJ)
	@make -s clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@printf "$(RED)Removing executable $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@rm -rf $(MLX42_DIR)/build
	@make -s fclean -C $(LIBFT_DIR) --no-print-directory

re : fclean all

.PHONY : all clean fclean re