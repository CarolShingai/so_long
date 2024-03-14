/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:51:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/13 20:55:32 by cshingai         ###   ########.fr       */
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

	// mlx_resize_image(game->img.personage, TILE, TILE);
void	insert_img(t_game *game)
{
	game->img.floor = create_img(game->mlx, "./sprites/grass_tile.png");
	game->img.wall = create_img(game->mlx, "./sprites/block_tile.png");
	game->img.personage = create_img(game->mlx, "./sprites/reborn_1.png");
	game->img.exit = create_img(game->mlx, "./sprites/BrickHouse.png");
	game->img.collectable = create_img(game->mlx, "./sprites/collectable.png");
	game->img.enemy = create_img(game->mlx, "./sprites/mafia_L2.png");
	game->img.text_space = create_img(game->mlx, "./sprites/text.png");
	mlx_resize_image(game->img.enemy, TILE, TILE);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (game->map.map[x][y] == '1')
				mlx_image_to_window(game->mlx, game->img.wall,
					y * TILE, x * TILE);
			else
				mlx_image_to_window(game->mlx, game->img.floor,
					y * TILE, x * TILE);
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
				mlx_image_to_window(game->mlx, game->img.exit,
					y * TILE, x * TILE);
					game->img.exit->instances[0].enabled = false;
			}
			else if (game->map.map[x][y] == 'C')
				mlx_image_to_window(game->mlx, game->img.collectable,
					y * TILE, x * TILE);
			else if (game->map.map[x][y] == 'P')
				mlx_image_to_window(game->mlx, game->img.personage,
					y * TILE, x * TILE);
			else if (game->map.map[x][y] == 'V')
				mlx_image_to_window(game->mlx, game->img.enemy,
					y * TILE, x * TILE);
		}
		x++;
	}
}

void	draw_text_space(t_game *game)
{
	char	*str;

	str = "Movimentos: ";
	// mlx_image_to_window(game->mlx, game->img.text_space, TILE, TILE);
	mlx_delete_image(game->mlx, game->img.text);
	game->img.text = mlx_put_string(game->mlx, ft_itoa(game->count_mov), 3 * 64, 0);
	mlx_put_string(game->mlx, str, 64, 0);
	// mlx_put_string(game->mlx, ft_itoa(game->count_mov), 3 * 64, 0);
	mlx_image_to_window(game->mlx, game->img.text, TILE, 0);
}
