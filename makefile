# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:55:05 by cshingai          #+#    #+#              #
#    Updated: 2024/01/31 17:21:04 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= so_long
FLAGS:= -Wextra -Werror -Wall -Wunreachable-code -Ofast
LIBMLX:= lib/MLX42
LIBFT:= lib/libft

HEADERS:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS:= $(wildcard srcs/*.c)
OBJ:= $(SRCS:srcs/%.c=obj/%.o)

all: ${NAME}

$(NAME): libft libmlx ${OBJ}
		@cc $(FLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
		@printf "Compiling ${NAME}\n"

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
		@make -C $(LIBFT) all

obj/%.o: srcs/%.c
		@mkdir -p obj
		@cc $(FLAGS) -c $(HEADERS) $< -o $@
		@printf "Compiling: $<\n"

clean:
		@rm -rf $(OBJ)
		@rm -rf $(LIBMLX)/build
		@make -C $(LIBFT) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT) fclean

re: fclean all
