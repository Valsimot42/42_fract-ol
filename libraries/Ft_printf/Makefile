# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 10:43:47 by tbolkova          #+#    #+#              #
#    Updated: 2022/08/01 19:49:37 by tbolkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_print.c printf_utils.c

OBJS = $(SRC:%.c=%.o)

LIBFT_OBJS = libft/*.o

# BONUS_OBJS = 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(OBJS)
	$(MAKE) -C libft
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

$(NAME): all

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
# add bonus here later

fclean: clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re: fclean all

.PHONY: all clean fclean re
# include bonus here later