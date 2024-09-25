# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 13:13:36 by nmeintje          #+#    #+#              #
#    Updated: 2024/09/04 13:01:18 by nmeintje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# directories
MLX_DIR = ./lib/MLX42
SRC_DIR = ./srcs
BONUS_DIR = ./bonus
OBJ_DIR = $(SRC_DIR)/objects
BONUS_OBJ_DIR = $(BONUS_DIR)/bonus_objects

# src / obj files
SOURCES = fractol.c \
		colors.c \
		hooks.c	\
		initialization.c \
		utils.c \

BONUS = fractol_bonus.c \
		colors_bonus.c \
		hooks_bonus.c \
		init_bonus.c \
		utils_bonus.c \

SRCS = $(addprefix $(SRC_DIR)/,$(SOURCES))
BONUS_SRC = $(addprefix $(BONUS_DIR)/,$(BONUS))

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))
BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJ_DIR)/%.o,$(notdir $(BONUS)))

HEADERS =  -I ./include -I $(MLX_DIR)
BONUS_HEADERS = -I ./include_bonus -I $(MLX_DIR)

MLXLIB = $(MLX_DIR)/build/libmlx42.a

# MLX42 dependencies - dl dynamically loaded lib, 
# glfw graphics library framework m math library

MLXLIB_FLAGS = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -lm -lpthread

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(MLXLIB) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLXLIB) $(MLXLIB_FLAGS) $(HEADERS) -o $@

$(MLXLIB):
	@cd lib && git clone https://github.com/codam-coding-college/MLX42.git
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus: $(MLXLIB) $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(MLXLIB) $(MLXLIB_FLAGS) $(BONUS_HEADERS) -o $(NAME)_bonus

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS_HEADERS) -c $< -o $@

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(BONUS_OBJ_DIR)
	@$(RM) $(MLX_DIR)/build
	
fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME)_bonus
		@$(RM) $(MLX_DIR)
		
re:		fclean all

.PHONY: all bonus clean fclean re
