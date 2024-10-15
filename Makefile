# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 21:52:59 by uzanchi           #+#    #+#              #
#    Updated: 2024/09/28 14:40:07 by uzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

FLAG		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./libraries/Libft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	so_long.c			\
				ft_check_map.c		\
				ft_close_game.c		\
				ft_free_memory.c	\
				ft_handle_input.c	\
				ft_init_game.c		\
				ft_init_map.c		\
				ft_render_map.c		\
				ft_flood_fill.c		\
				ft_utils.c

SRC_DIR		=	./sources/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

DEP			=	$(OBJ:.o=.d)

.c.o:
	$(CC) $(FLAG) -I $(INC_DIR) -MMD -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

# Compilation du programme final
$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	@echo "\033[0;33m\nLINKING $(NAME)...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m$(NAME) created\n"

# On ajoute les fichiers objets en tant que dépendances pour éviter de relinker à chaque fois
$(LIBFT_LIB): 
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@make -C $(MLX_PATH)

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ) $(DEP)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re lib mlx
