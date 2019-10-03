# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 11:22:48 by jcanteau          #+#    #+#              #
#    Updated: 2019/10/02 17:46:37 by lgudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
HEAD = fdf.h
SRC = main.c read.c ../libft/libft.a
OBJ = $(SRC:.c=.o)

MLXFLAG = -I /usr/local/include
MLXLIB = -L /usr/local/lib -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit

$(CC) = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLXFLAG) $(OBJ) $(MLXLIB) $(FRAMEWORK) -o $(NAME)

$(OBJ): %.o: %.c $(HEAD) 
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
