/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:23:19 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/23 19:45:15 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/src/ft_printf.h"

# define WIDTH 1024
# define HEIGHT 1024
# define TRUE 1
# define FALSE 0

# define LESS_ARGS "ERROR! you need to pass the map file as a argument."
# define MORE_ARGS "ERROR! you had surpassed the number of arguments."
# define NOT_SQUARE "ERROR! the map is not square"
# define EMPTY_LINE "ERROR! unvalid map, there is a empty line."
# define EXTENSION "ERROR! the map must be a archive .ber"
# define ALLOCATION "ERROR! memory allocation problem."
# define OPEN_FILE "ERROR! problem in opening the file."
# define EMPTY_MAP "ERROR! the map is empty"

typedef struct s_position
{
  int x;
  int y;
} t_position;

typedef struct s_map
{
  int width;
  int height;
} t_map;

typedef struct s_game
{
  char **map;
} t_game;


int buffer_noempty_line(char *temp_buffer, int char_read);
mlx_image_t *create_img(mlx_t *mlx, char *img_path);
int check_map_chars(char **map);
int check_square(t_map game_map, char **map);
// void  check_map(char **map);
int empty_map(char **map);
int find_height(char **map);
void *ft_free_split(char **split);
void primary_validation(int argc, char *argv);
void set_game_map(char **map);
char **read_line(char *map_path);
int  ft_error(char *msg);

#endif
