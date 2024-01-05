# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 22:57:02 by vgabovs           #+#    #+#              #
#    Updated: 2023/12/18 13:40:12 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard src/*.c src/normal/*.c)
BONUS_SRC = $(wildcard src/*.c src/bonus/*.c)
OBJ	= $(SRC:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)
LIBFTDIR = ./inc/libft
LIBFTA = $(LIBFTDIR)/libftprintf.a
SO_LONG_H = inc/so_long.h

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LFLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/include/../lib -lXext -lX11 -lm

CC = gcc
CCS = $(CC) -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -Iinc #-I$(LIBFTDIR) #-I$(MLX_DIR)

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
RED='\033[31m'

VALG = valgrind --leak-check=full #--show-leak-kinds=all #--show-error-list=yes
AT = leaks -atExit --

USE_SANITIZER = 1

ifeq ($(USE_SANITIZER), 1)
	CCFLAGS = $(CCS)
else
	CCFLAGS = $(CC)
endif

define INTRO
+--------------------------------------------------------+
|_______________       ______ _______ _____   ___________|
|__  ___/__  __ \      ___  / __  __ \___  | / /__  ____/|
|_____ \ _  / / /      __  /  _  / / /__   |/ / _  / __  |
|____/ / / /_/ /       _  /___/ /_/ / _  /|  /  / /_/ /  |
|/____/  \____/________/_____/\____/  /_/ |_/   \____/   |
|              _/_____/                                  |
+--------------------------------------------------------+
endef
export INTRO


all: $(NAME)

$(NAME): $(OBJ) $(LIBFTA) $(MLX) $(SRC)
	@$(CCFLAGS) $(OBJ) $(LFLAGS) -g -o $@ $(LIBFTA)
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@echo "$$INTRO"

$(OBJ_DIR)/%.o:%.c $(SO_LONG_H) $(LIBFTA)
	@echo $(CURSIVE)$(GRAY) "    - Building $<" $(NONE)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/src/normal
	@mkdir -p $(OBJ_DIR)/src/bonus
	@if [ "$(USE_SANITIZER)" = "1" ]; then $(CCS) $(CFLAGS) -c $< -o $@ ; else $(CC) $(CFLAGS) -c $< -o $@ ; fi
#	@$(CC) $(CFLAGS) -c $< -o $@


$(LIBFTA):
	@make all -C $(LIBFTDIR)

$(MLX):
	@make -C $(MLX_DIR)

bonus: $(BONUS_OBJ) $(LIBFTA) $(MLX) $(BONUS_SRC)
	@$(CCFLAGS) $(BONUS_OBJ) $(LFLAGS) -g -o so_long $(LIBFTA)
	@echo $(GREEN)"     - Compiled with BONUS-"$(NONE)
	@echo "$$INTRO"

val: USE_SANITIZER = 0
val: fclean $(OBJ) $(LIBFTA) $(MLX) $(SRC)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME) $(LIBFTA)
	$(VALG) ./$(NAME) maps/111.ber
	@echo $(GREEN)"- Compiled with valgrind-"$(NONE)

at: USE_SANITIZER = 0
at: fclean $(OBJ) $(LIBFTA) $(MLX) $(SRC)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME) $(LIBFTA)
	@$(AT) ./$(NAME) maps/111.ber
	@echo $(GREEN)"- Compiled with atExit-"$(NONE)

clean:
	@make -C $(LIBFTDIR) clean
#	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all bonus val at re clean fclean
