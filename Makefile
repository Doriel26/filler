# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 17:49:15 by dchiche           #+#    #+#              #
#    Updated: 2018/05/03 21:34:41 by dchiche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dchiche.filler
FLAGS = -Wall -Wextra -Werror
LIB = ./
SRCS = srcs/main.c srcs/board.c srcs/place_piece.c srcs/free_block.c \
	   srcs/parse_piece.c
OBJ = $(SRCS:.c=.o)

all : lib $(NAME)

$(NAME) : $(OBJ)
	@gcc -o $(NAME) $(OBJ) -L./libft/ -lft
	@echo "> Filler has been made :)"

lib :
	@make -C ./libft/ all

%.o : %.c
	@echo "=\c"
	@gcc $(FLAGS) -I $(LIB) -c $? -o $@

clean :
	@echo "----> Filler has been cleaned :)"
	@rm -rf $(OBJ)
	@make -C ./libft/ fclean

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: fclean lib clean re all
