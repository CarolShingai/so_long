/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:51:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/14 20:18:11 by cshingai         ###   ########.fr       */
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
	game->img.personage_r = create_img(game->mlx, "./sprites/reborn_1.png");
	game->img.personage_l = create_img(game->mlx, "./sprites/reborn_L1.png");
	game->img.exit = create_img(game->mlx, "./sprites/BrickHouse.png");
	game->img.collectable = create_img(game->mlx, "./sprites/collectable.png");
	game->img.enemy = create_img(game->mlx, "./sprites/mafia_L2.png");
	mlx_resize_image(game->img.enemy, TILE, TILE);
	game->img.scroll = create_img(game->mlx, "./sprites/scroll.png");
	mlx_resize_image(game->img.scroll, TILE * 1.5, (TILE / 2) + 20);
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
			else if (game->map.map[x][y] == 'V')
				mlx_image_to_window(game->mlx, game->img.enemy,
					y * TILE, x * TILE);
		}
		x++;
	}
}

void	draw_text_space(t_game *game)
{
	char	*src;

	mlx_delete_image(game->mlx, game->img.text);
	src = ft_itoa(game->count_mov);
	mlx_image_to_window(game->mlx, game->img.scroll, TILE, 0);
	game->img.text = mlx_put_string(game->mlx, src, 2 * 64 - 12, 14);
	// mlx_put_string(game->mlx, src, 2 * TILE, 14);
	// mlx_image_to_window(game->mlx, game->img.text, TILE, 0);
}
