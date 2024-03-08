/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:23:19 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/08 19:57:52 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
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
# define TILE 64
# define TRUE 1
# define FALSE 0

# define LESS_ARGS "ERROR! You need to pass the map file as a argument."
# define MORE_ARGS "ERROR! You had surpassed the number of arguments."
# define NOT_SQUARE "ERROR! The map is not square"
# define EMPTY_LINE "ERROR! Unvalid map, there is a empty line."
# define EXTENSION "ERROR! The map must be a archive '.ber'."
# define ALLOCATION "ERROR! Memory allocation problem."
# define OPEN_FILE "ERROR! Problem in opening the file."
# define EMPTY_MAP "ERROR! The map is empty."
# define TEXTURE_ERROR "ERROR! Problem with the texture image."
# define IMAGE_ERROR "ERROR! Problem loading the image."
# define BORDER_WRONG "ERROR! Wrong char in the border."
# define COLLECTABLE "ERROR! There is no collectables in the map."
# define PERSONAGE "ERROR! There isn't a personage in the map."
# define EXIT "ERROR! There isn't a exit in the map."
# define EXTRA_PERS "ERROR! There is more than one personage in the map."
# define EXTRA_EXIT "ERROR! There is more than one exit in the map."
# define PATH_ERROR "ERROR! It is impossible to get to the exit."

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*personage;
	mlx_image_t	*exit;
	mlx_image_t	*collectable;
}	t_img;

typedef struct s_position
{
	int32_t			x;
	int32_t			y;
}	t_position;

typedef enum e_moviment
{
	right = 1,
	left = -1,
	up = -1,
	down = 1,
}	t_moviment;

typedef struct s_itens
{
	int	num_p;
	int	num_c;
	int	num_e;
}	t_itens;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			n_colectable;
	t_position	personage;
}				t_map;

//t_img
typedef struct s_game
{
	t_map	map;
	mlx_t	*mlx;
	t_img	img;
	int		n_mov;
	int		player_collectables;

}	t_game;

//map_validation.c
int		buffer_noempty_line(char *temp_buffer, int char_read);
int		check_map_chars(char *map);
int		check_shape(char **map, t_map game_map);
void	check_map_game(char **map, t_game game_map);
int		check_border(char **map, t_map game_map);

//map_validation2.c
int		check_num_itens(t_map game_map);
int		count_itens(char **map, char item);
int		check_flood_fill(t_map game_map);
void	fload_fill(char **map, int x, int y);

//create_img.c
mlx_image_t	*create_img(mlx_t *mlx, char *img_path);
void	insert_img(t_game *game);
void	draw_map(t_game *game);
void	draw_special_tile(t_game *game);

//read_map.c
void	primary_validation(int argc, char *argv);
void	start(char *argv);
char	**read_line(char *map_path);

//set_game_map.c
int		find_height(char **map);
void	set_game_map(char **map, t_game *game);
void	set_personage(t_game *game);

//erroc.c
int		ft_error(char *msg);

//free_split.c
void    *ft_free_split(char **split);

//init_game.c
void	init_game(t_game *game);

//moviment.c
void	key_action(mlx_key_data_t keydata, void* param);
void	personage_moviment_vertical(t_game *game, int pers_x, int pers_y, t_moviment mov);
void	personage_moviment_horizontal(t_game *game, int pers_x, int pers_y, t_moviment mov);
void	get_collectables(t_game *game);

#endif
