# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#*   Updated: 2017/01/18 14:47:44 by cfatrane         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./srcs/

SRC_NAME =	main.c					\
			ft_check.c				\
			ft_fdf.c				\
			ft_create_map.c			\
			ft_mlx.c				\
			ft_init.c				\
			ft_bresenham.c			\
			ft_pixel_put.c			\
			ft_draw.c				\
			ft_point.c				\
			ft_hook.c				\
			ft_key_hook_move.c		\
			ft_key_hook_color.c		\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CPPFLAGS = -I./includes/

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C./libft/
	@echo "Creation of $(NAME) ..."
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	@echo "$(NAME) created"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Removal of .o files of $(NAME) ..."
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Files .o deleted\n"


fclean: clean
	@make fclean -C ./libft/
	@echo "Removal of $(NAME)..."
	@rm -f $(NAME)
	@echo "Binary $(NAME) deleted\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
