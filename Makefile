# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 14:33:31 by mdovhopo          #+#    #+#              #
#    Updated: 2018/11/24 14:33:33 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = v1_fdf

MAP = ./fdf/maps/42.fdf

FLAGS = -Wall -Wextra -Werror

INCLUDES = minilibx_macos

GNL_INC = get_next_line

SRC_GNL = $(GNL_INC)/get_next_line.c $(GNL_INC)/libft/libft.a

SRC_C = fdf.c render.c grid.c line.c vec3d.c isoprojection.c readmap.c rect.c del_win.c

SOME_STAFF_FOR_MLX = -L minilibx_macos -lmlx -framework OpenGL -framework Appkit

SRC_O = $(SRC_C:.c=.o)

CC = clang

%.o: %.c
	$(CC) -o $@ -c $<

all: $(NAME) libft

$(NAME): $(SRC_O)
	$(CC) -o $(NAME) -I $(INCLUDES) $(SRC_O) $(SRC_GNL) $(SOME_STAFF_FOR_MLX)

libft:
	cd get_next_line/libft && make && cd ../../

test:
	clang test.c -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
	./a.out

clean:	
	@/bin/rm -f $(SRC_O)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all

magic:
	clear
	@echo "*making magic*"
	@echo " 	.∧＿∧"
	@echo " 	( ･ω･｡)つ━☆・*。"
	@echo "	⊂　 ノ 　　　・゜+."
	@echo "	しーＪ　　　°。+ *´¨)"
	@echo "                 .· ´¸.·*´¨) ¸.·*¨)"
	@echo "　　　　　　　　(¸.·´ (¸.·'* ☆"
