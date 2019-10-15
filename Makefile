# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 23:00:49 by lgudin            #+#    #+#              #
#    Updated: 2019/10/15 12:02:14 by lgudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = ./
OBJ_PATH = ./obj/
INC_PATH = ./includes

NAME = fdf

SRC_NAME = main.c\
		   bresenham_tarace.c\
		   color_modes.c\
		   color_set.c\
		   hook.c\
		   init.c\
		   keyhook_set.c\
		   lock_screen.c\
		   laby_mode\
		   player_move.c\
		   mallocator.c\
		   print.c\
		   projection.c\
		   read.c\
		   tools.c\

TMP = tmp.txt

OBJ_NAME = $(SRC_NAME:.c=.o)\
			../../libft/libft.a\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[33mTenez ! Attention les .o sont encore chauds !\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32mAvec ceci ? un executable ? Emballé c'est pesé !\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[36mLaissez moi virer tout ces machins completement périmés..\033[0m"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean

segfault:
	@echo "[1]    24109 segmentation fault"
	
america_great_again:
	@echo "|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n| * * * * * * * * *  :::::::::::::::::::::::::|\n|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n| * * * * * * * * *  :::::::::::::::::::::::::|\n|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n| * * * * * * * * *  :::::::::::::::::::::::::|\n|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n|:::::::::::::::::::::::::::::::::::::::::::::|\n|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n|:::::::::::::::::::::::::::::::::::::::::::::|\n|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n|:::::::::::::::::::::::::::::::::::::::::::::|\n|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO| \n ";