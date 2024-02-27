/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:23:19 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/27 19:47:22 by cshingai         ###   ########.fr       */
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
# define TEXTURE_ERROR "ERROR! problem with the texture image"
# define IMAGE_ERROR "ERROR! problem loading the image"
# define BORDER_WRONG "ERROR! wrong char in the border"

typedef struct s_image
{
  int x;
  int y;
  mlx_image_t *img;
} t_image;

typedef struct s_map
{
  char **map;
  int width;
  int height;
} t_map;

typedef struct s_game
{
  t_map map;
  mlx_t mlx;
} t_game;

//map_validation.c
int buffer_noempty_line(char *temp_buffer, int char_read);
int check_map_chars(char *map);
int check_square(char **map, t_map game_map);
void  check_map_game(char **map, t_map game_map);
int game_border(char **map, t_map game_map);
//create_img.c
mlx_image_t *create_img(mlx_t *mlx, char *img_path);
//read_map.c
void  primary_validation(int argc, char *argv);
void	start(char *argv);
char **read_line(char *map_path);
//set_game_map.c
void	set_game_map(char **map, t_map *game_map);
int find_height(char **map);
//erroc.c
int  ft_error(char *msg);
// void *ft_free_split(char **split);

#endif
