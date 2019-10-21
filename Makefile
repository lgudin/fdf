# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgudin <lgudin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 23:00:49 by lgudin            #+#    #+#              #
#    Updated: 2019/10/18 09:30:01 by lgudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

MLX = ./minilibx_macos/libmlx.a

LIB =./.libft/libft.a

NAME = fdf

SRC_NAME =	main.c\
			bresenham.c\
			color_modes.c\
			color_set.c\
			hook.c\
			init.c\
			keyhook_set.c\
			keyhook_setb.c\
			lock_screen.c\
			mallocator.c\
			player_check_set.c\
			player_move.c\
			print_main.c\
			print.c\
			projection.c\
			read.c\
			tools.c\
			get_lines.c

OBJ_NAME = $(SRC_NAME:.c=.o)\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[31mUne libft ? Attendez je vais voir si ya des news\033[0m"
	@cd ./.libft;make;
	@echo "\033[33mCa compile attendez..   Ahh ! Tenez ! Attention les .o sont encore chauds !\033[0m"
	@$(CC) $(CFLAGS) $(MLX) $(LIB) $(OBJ) -o $(NAME) $(FRAMEWORK) -fsanitize=address
	@echo "\033[32mAvec ceci ? un executable ? et un $(NAME) pour la 'tite dame .. Emballé c'est pesé !\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(HEAD)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[36mLaissez moi virer tout ces machins completement périmés..\033[0m"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

segfault:
	@echo "[1]    24109 segmentation fault"
	
america_great_again:
	@echo "|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n| * * * * * * * * *  :::::::::::::::::::::::::|\n|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n| * * * * * * * * *  :::::::::::::::::::::::::|\n|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n| * * * * * * * * *  :::::::::::::::::::::::::|\n|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n|:::::::::::::::::::::::::::::::::::::::::::::|\n|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n|:::::::::::::::::::::::::::::::::::::::::::::|\n|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n|:::::::::::::::::::::::::::::::::::::::::::::|\n|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO| \n ";