# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 13:13:36 by nmeintje          #+#    #+#              #
#    Updated: 2024/08/01 10:52:22 by nmeintje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# directories
MLX_DIR = ./lib/MLX42
LIBFT_DIR = ./lib/libft
SRC_DIR = ./srcs

#src / obj files
SOURCES = fractol.c \

SRCS = $(addprefix $(SRC_DIR)/,$(SOURCES))

OBJS = $(SRCS:.c=.o)

HEADERS =  -I ./include -I $(MLX_DIR)/include -I $(LIBFT_DIR)

# MLX42 dependencies - dl dynamically loaded lib, glfw graphics library framework m math library

MLXLIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -lm -lpthread

LIBFT = -L $(LIBFT_DIR) -lft

cc = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c -I $(HEADERS) $< -o $(<:.c=.o)

$(NAME): mlx libft $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLXLIB) $(HEADERS) -o $@

mlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

libft:
	@make -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(SRC_DIR)/build
	@make -C $(LIBFT_DIR) clean

fclean: clean
		@$(RM) $(NAME)
		@make -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all mx libft clean fclean re
