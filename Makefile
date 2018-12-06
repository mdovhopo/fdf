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

SRC = src

MLX = /usr/local/lib

f = -Wall -Wextra -Werror 

FLAGS = 

SRC_C = $(addprefix $(SRC)/, fdf.c isoprojection.c grid.c deal_key.c mouse_pressed.c line.c readmap.c render.c print_usage.c del_win.c interface.c)

FRAMEWORKS = -framework OpenGL -framework Appkit

SRC_O = $(SRC_C:.c=.o)

CC = clang

all: $(NAME)

libft/libft.a:
	@make -C $(LIBFT)

$(NAME): libft/libft.a $(SRC_O)
	@$(CC) $(FLAGS) -I $(INC) -o $(NAME) $(SRC_O) -L $(LIBFT) -lft $(GNL)/get_next_line.c -L $(MLX) -lmlx $(FRAMEWORKS)
	@echo "$(NAME) Has been created, run ./$(NAME) <map>"

$(SRC)/%.o: $(SRC)/%.c | src
	@$(CC) $(FLAGS) -I $(INC) -I . -c $< -o $@

clean:	
	@/bin/rm -f $(SRC_O)

lclean:
	make -C $(LIBFT) fclean
	make fclean

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

