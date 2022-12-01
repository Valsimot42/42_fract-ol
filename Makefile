# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 12:48:25 by tbolkova          #+#    #+#              #
#    Updated: 2022/12/01 15:12:34 by tbolkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Removal
RM = rm -f

# Libraries
MLX = libraries/mlx/libmlx.a -framework OpenGL -framework AppKit
LIBFT = libraries/Ft_printf/Libft/libft.a
PRINTF = libraries/Ft_printf/Libftprintf.a

# Source and object files
SRC =	src/main.c \
		src/mandelbrot.c \
		src/julia.c \
		src/window.c \
		src/utils.c \
		src/help.c
			
OBJ = $(SRC:%.c=%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libraries/mlx
	$(MAKE) -C libraries/Ft_printf
	$(MAKE) -C libraries/Ft_printf/Libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	$(MAKE) clean -C libraries/mlx
	$(MAKE) clean -C libraries/Ft_printf
	$(MAKE) clean -C libraries/Ft_printf/Libft
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) fclean -C libraries/Ft_printf
	$(MAKE) fclean -C libraries/Ft_printf/Libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re