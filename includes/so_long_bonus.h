/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:03:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/26 20:38:07 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

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
# define RED "\x1B[31m"

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
# define W_CHAR "ERROR! There is a not identify charecter in the map."

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*personage_r1;
	mlx_image_t	*personage_r2;
	mlx_image_t	*personage_r3;
	mlx_image_t	*personage_l1;
	mlx_image_t	*personage_l2;
	mlx_image_t	*personage_l3;
	mlx_image_t	*exit;
	mlx_image_t	*collectable;
	mlx_image_t	*enemy;
	mlx_image_t	*enemy2;
	mlx_image_t	*enemy3;
	mlx_image_t	*enemy4;
	mlx_image_t	*scroll;
	mlx_image_t	*text;
	mlx_image_t	*death_msg;
	mlx_image_t	*win_msg;
}	t_img;

typedef struct s_position
{
	int32_t	x;
	int32_t	y;
}	t_position;

typedef enum e_moviment
{
	RIGHT = 1,
	LEFT = -1,
	UP = -1,
	DOWN = 1,
}	t_moviment;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			box_to_collect;
	t_position	personage;
	t_position	exit;
	t_position	enemy;
}	t_map;

typedef struct s_enemy
{
	t_moviment	direction;
	int			to_move;
}	t_enemy;

typedef struct s_game
{
	t_map			map;
	mlx_t			*mlx;
	t_img			img;
	t_bool			exit_status;
	t_bool			game_status;
	t_bool			walking_status;
	mlx_texture_t	*icon;
	t_moviment		mov;
	t_enemy			enemy;
	int				count_mov;
	int				player_collectables;
	int				count_enemies;
}	t_game;

// map_validation.c
t_bool		buffer_noempty_line(char *temp_buffer, int char_read);
t_bool		check_map_chars(char *map);
t_bool		check_shape(char **map, t_map game_map);
void		check_map_game(char **map, t_game game_map);
t_bool		check_border(char **map, t_map game_map);

// map_validation2.c
int			count_itens(char **map, char item);
t_bool		check_flood_fill(t_map game_map);
void		fload_fill(char **map, int x, int y);

// create_img.c
mlx_image_t	*create_img(mlx_t *mlx, char *img_path);
void		insert_img(t_game *game);
void		insert_img2(t_game *game);
void		draw_map(t_game *game);
void		draw_special_tile(t_game *game);

// create_img_bonus2.c
void		draw_personage(t_game *game);
void		draw_personage2(t_game *game);
void		draw_enemy(t_game *game);
void		draw_personage_dir(t_game *game, t_moviment mov);
void		draw_text_space(t_game *game);

// read_map.c
void		primary_validation(int argc, char *argv);
void		start(char *argv);
char		**read_line(char *map_path);

// set_game_map.c
int			find_height(char **map);
void		set_game_map(char **map, t_game *game);
void		set_personage(t_game *game);
void		set_exit(t_game *game);
void		set_enemy(t_game *game);

// erroc.c
int			ft_error(char *msg);
int			error(char *msg, t_game *game);
void		*ft_free_split(char **split);

// init_game.c
void		init_game(t_game *game);
void		setting_window(t_game *game);

// moviment.c
void		key_action(mlx_key_data_t keydata, void *param);
void		personage_moviment_vertical(t_game *game, int pers_x,
				int pers_y, t_moviment mov);
void		personage_moviment_horizontal(t_game *game, int pers_x,
				int pers_y, t_moviment mov);
void		enemy_shock(t_game *game, int pers_x, int pers_y);
void		get_collectables(t_game *game, int pers_x, int pers_y);

// moviments_bonus2.c
void		update_img_vertical(t_game *game, t_moviment mov);
void		update_img_horizontal(t_game *game, t_moviment mov);
void		set_target(t_game *game, t_moviment mov);

// animate_img.c
void		count_loop(void *param);
void		animate_player_right(t_game *game, int time);
void		animate_player_left(t_game *game, int time);
void		disable_left(t_game *game);
void		disable_right(t_game *game);

// animate_enemy.c
void		count_loop_enemy(void *param);
void		animate_enemy(t_game *game, int time);
void		animate_enemy2(t_game *game);

// move_enemy.c
void		move_enemy(t_game *game);
void		move_enemy_right(t_game *game, int i);
void		move_enemy_left(t_game *game, int i);
t_bool		valid_position_enemy_left(t_game *game, int x, int y);
t_bool		valid_position_enemy_right(t_game *game, int x, int y);
void		enemy_map_position(t_game *game);

// finish.c
void		enable_exit(t_game *game);
void		finish_game(t_game *game);

#endif
