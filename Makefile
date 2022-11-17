# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 12:48:25 by tbolkova          #+#    #+#              #
#    Updated: 2022/11/17 15:29:21 by tbolkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Libraries
# MLX = libraries/mlx/libmlx.a -framework OpenGL -framework AppKit
# LIBFT = Libraries/Ft_printf/Libft/libft.a
# PRINTF = Libraries/Ft_printf/libftprintf.a

#Source and object files
SRCS	= Libraries/files/main.c 
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re
