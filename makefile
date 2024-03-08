# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:55:05 by cshingai          #+#    #+#              #
#    Updated: 2024/03/07 20:05:26 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= so_long
FLAGS:= -Wextra -Werror -Wall -Wunreachable-code -Ofast -g3
LIBMLX:= lib/MLX42
LIBFT:= lib/libft
FT_PRINTF:= lib/ft_printf

HEADERS:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm
SRCS:= ${addprefix srcs/, \
			create_img.c \
			error.c \
			free_split.c \
			init_game.c \
			main.c \
			map_validation2.c \
			map_validation.c \
			moviments.c \
			read_map.c \
			set_game_map.c \
		}
OBJ:= $(SRCS:srcs/%.c=obj/%.o)

all: ${NAME}

$(NAME): libft libmlx ft_pritf ${OBJ}
		@cc $(FLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
		@printf "Compiling ${NAME}\n"

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

clean:
		@rm -rf $(OBJ)
		@rm -rf $(LIBMLX)/build
		@make -C $(LIBFT) clean
		@make -C $(FT_PRINTF) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT) fclean
		@make -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all, libmlx, libft, ft_pritf, clean, fclean, re
