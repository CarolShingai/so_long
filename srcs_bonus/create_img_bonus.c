/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:51:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/11 00:41:03 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

mlx_image_t	*create_img(mlx_t *mlx, char *img_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(img_path);
	if (!texture)
		ft_error(TEXTURE_ERROR);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error(IMAGE_ERROR);
	mlx_delete_texture(texture);
	return (img);
}

void	insert_img(t_game *game)
{
	game->img.floor = create_img(game->mlx, "./sprites/grass_tile.png");
	game->img.wall = create_img(game->mlx, "./sprites/tree_tile.png");
	mlx_resize_image(game->img.wall, TILE, TILE);
	game->img.personage = create_img(game->mlx, "./sprites/reborn_1.png");
	// mlx_resize_image(game->img.personage, TILE, TILE);
	game->img.exit = create_img(game->mlx, "./sprites/BrickHouse.png");
	game->img.collectable = create_img(game->mlx, "./sprites/collectable.png");
	game->img.enemy = create_img(game->mlx, "./sprites/mafia_R1.png");
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.map[x])
	{
		y = 0;
		while(game->map.map[x][y])
		{
			if (game->map.map[x][y] == '1')
				mlx_image_to_window(game->mlx, game->img.wall, y * TILE, x * TILE);
			else
				mlx_image_to_window(game->mlx, game->img.floor, y * TILE, x * TILE);
			y++;
		}
		x++;
	}
}

void	draw_special_tile(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.map[x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'E')
			{
				mlx_image_to_window(game->mlx, game->img.exit, y * TILE, x * TILE);
				game->img.exit->instances[0].enabled = false;
			}
			else if (game->map.map[x][y] == 'C')
				mlx_image_to_window(game->mlx, game->img.collectable, y * TILE, x * TILE);
			else if (game->map.map[x][y] == 'P')
				mlx_image_to_window(game->mlx, game->img.personage, y * TILE, x * TILE);
			else if (game->map.map[x][y] == 'V')
				mlx_image_to_window(game->mlx, game->img.enemy, y * TILE, x * TILE);
		}
		x++;
	}
}

// void	draw_personage(t_game *game)
// {

// }
