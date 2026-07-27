# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 18:24:35 by pucci17pink       #+#    #+#              #
#    Updated: 2026/07/27 14:05:46 by canoduran        ###   ########.fr        #
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
CFLAGS    = -Wall -Wextra -Werror -I include -I mlx -I libft -I get_next_line
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
GNL_DIR   = get_next_line
MLX_DIR   = mlx
MLX       = $(MLX_DIR)/libmlx.a

# --- DIRECTORIES ---
DIR_SRC     = src
DIR_MAP     = $(DIR_SRC)/map
DIR_PARSING = $(DIR_SRC)/parsing
DIR_CLEAR   = $(DIR_SRC)/clear
OBJ_DIR     = obj

# --- SOURCES ---
SRC = $(DIR_SRC)/main.c \
	$(DIR_MAP)/check_filename.c \
	$(DIR_MAP)/take_map.c \
	$(DIR_SRC)/init.c \
	$(DIR_PARSING)/check_map.c \
	$(DIR_PARSING)/check_players.c \
	$(DIR_PARSING)/floodfil.c \
	$(DIR_PARSING)/parse_elements.c\
	$(DIR_PARSING)/parse_utils.c\
	$(DIR_CLEAR)/clear_core.c \
	$(DIR_CLEAR)/utils.c \
	$(DIR_SRC)/render/player.c \
	$(DIR_SRC)/render/init_game.c \
	$(DIR_SRC)/render/minimap.c \
	$(DIR_SRC)/render/hooks.c \
	$(DIR_SRC)/render/hooks_key.c \
#      $(DIR_MAP)/check_filename.c \
#      $(DIR_MAP)/take_map.c \
#      $(DIR_SRC)/init.c \
#      $(DIR_PARSING)/parsing.c \
#      $(DIR_PARSING)/utils.c \
#      $(GNL_DIR)/get_next_line.c \
#      $(GNL_DIR)/get_next_line_utils.c

# --- GNL SOURCES ---
GNL_SRC = $(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

# --- OBJECTS ---
OBJ = $(SRC:$(DIR_SRC)/%.c=$(OBJ_DIR)/%.o)
GNL_OBJ = $(GNL_SRC:$(GNL_DIR)/%.c=$(OBJ_DIR)/gnl/%.o)

# --------------------------------------------------------
#        BARRE DE PROGRESSION (ROSE) POUR COMPILATION
# --------------------------------------------------------

NB := $(words $(OBJ) $(GNL_OBJ))
BARLEN = 30
COUNTER = 0

$(OBJ_DIR)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(dir $@)
	@$(eval COUNTER := $(shell echo $$(($(COUNTER) + 1))))
	@$(eval PROG := $(shell echo $$(($(COUNTER) * 100 / $(NB))) ))
	@$(eval FILLED := $(shell echo $$(($(PROG) * $(BARLEN) / 100)) ))
	@$(eval EMPTY := $(shell echo $$(($(BARLEN) - $(FILLED))) ))
	@printf "\r\033[35m[%s%s] %3s%%\033[0m  \033[90m%-40s\033[0m" \
		$$(printf "#%.0s" $$(seq 1 $(FILLED))) \
		$$(printf ".%.0s" $$(seq 1 $(EMPTY))) \
		"$(PROG)" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/gnl/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(eval COUNTER := $(shell echo $$(($(COUNTER) + 1))))
	@$(eval PROG := $(shell echo $$(($(COUNTER) * 100 / $(NB))) ))
	@$(eval FILLED := $(shell echo $$(($(PROG) * $(BARLEN) / 100)) ))
	@$(eval EMPTY := $(shell echo $$(($(BARLEN) - $(FILLED))) ))
	@printf "\r\033[35m[%s%s] %3s%%\033[0m  \033[90m%-40s\033[0m" \
		$$(printf "#%.0s" $$(seq 1 $(FILLED))) \
		$$(printf ".%.0s" $$(seq 1 $(EMPTY))) \
		"$(PROG)" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- RULES ---
all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@make -s -C $(MLX_DIR) CFLAGS="-std=gnu89 -O2" libmlx.a --no-print-directory; true

$(NAME): $(LIBFT) $(MLX) $(OBJ) $(GNL_OBJ)
	@echo
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) 2>/dev/null $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@make -s clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@printf "$(RED)Removing executable $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR) --no-print-directory

re : fclean all

.PHONY : all clean fclean re
