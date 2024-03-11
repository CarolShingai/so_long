# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:55:05 by cshingai          #+#    #+#              #
#    Updated: 2024/03/11 19:14:42 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= so_long
NAME_BONUS:= so_long_bonus
FLAGS:= -Wextra -Werror -Wall -Wunreachable-code -Ofast -g3
LIBMLX:= lib/MLX42
LIBFT:= lib/libft
FT_PRINTF:= lib/ft_printf

HEADERS:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm

SRCS:= ${addprefix srcs/, \
			create_img.c \
			error.c \
			init_game.c \
			main.c \
			map_validation2.c \
			map_validation.c \
			moviments.c \
			read_map.c \
			set_game_map.c \
			finish.c \
		}

SRCS_BONUS:= ${addprefix srcs_bonus/, \
			create_img_bonus.c \
			error_bonus.c \
			init_game_bonus.c \
			main_bonus.c \
			map_validation2_bonus.c \
			map_validation_bonus.c \
			moviments_bonus.c \
			read_map_bonus.c \
			set_game_map_bonus.c \
			finish_bonus.c \
			enemy_moviment_bonus.c \
		}

OBJ:= $(SRCS:srcs/%.c=obj/%.o)
OBJ_BONUS = $(SRCS_BONUS:srcs_bonus/%.c=obj_bonus/%.o)

all: ${NAME}

bonus : ${NAME_BONUS}

$(NAME): libft libmlx ft_pritf ${OBJ}
		@cc $(FLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
		@printf "Compiling ${NAME}\n"

$(NAME_BONUS): libft libmlx ft_pritf ${OBJ_BONUS}
		@cc $(FLAGS) $(OBJ_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)
		@printf "Compiling ${NAME_BONUS}\n"

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
		@make -C $(LIBFT) all

ft_pritf:
		@make -C $(FT_PRINTF) all

obj/%.o: srcs/%.c ./includes/so_long.h
		@mkdir -p obj
		@cc $(FLAGS) -c $(HEADERS) $< -o $@
		@printf "Compiling: $<\n"

obj_bonus/%.o: srcs_bonus/%.c ./includes/so_long_bonus.h
		@mkdir -p obj_bonus
		@cc $(FLAGS) -c $(HEADERS) $< -o $@
		@printf "Compiling: $<\n"

clean:
		@echo "Removing objects..."
		@rm -rf $(OBJ) $(OBJ_BONUS)
		@rm -rf $(LIBMLX)/build
		@make -C $(LIBFT) clean
		@make -C $(FT_PRINTF) clean

fclean: clean
		@echo "Removing executables..."
		@rm -rf $(NAME) $(NAME_BONUS)
		@echo "Removing libft.a..."
		@make -C $(LIBFT) fclean
		@make -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all, libmlx, libft, ft_pritf, clean, fclean, bonus, re
