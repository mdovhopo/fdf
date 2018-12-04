# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 20:40:56 by mdovhopo          #+#    #+#              #
#    Updated: 2018/12/04 20:40:59 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = fdf

LIBFT = libft

GNL =  get_next_line

INC = includes

MLX = /usr/local/lib

FLAGS = -Wall -Wextra -Werror -I$(INC)

SRC_C = fdf.c isoprojection.c grid.c deal_key.c mouse_pressed.c line.c \
		readmap.c render.c print_usage.c del_win.c

FRAMEWORKS = -framework OpenGL -framework Appkit

SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "Compiling libft..."
	@make -C $(LIBFT)
	@echo "Compiling project..."
	@$(CC) $(FLAGS) -o $(NAME) $(SRC_O) -L $(LIBFT) -lft $(GNL)/get_next_line.c -L $(MLX) -lmlx $(FRAMEWORKS)
	@echo "Done"

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

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

