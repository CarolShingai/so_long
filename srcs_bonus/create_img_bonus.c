/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:51:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/22 19:42:28 by cshingai         ###   ########.fr       */
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
	game->img.text = NULL;
	game->img.floor = create_img(game->mlx, "./sprites/grass_tile.png");
	game->img.wall = create_img(game->mlx, "./sprites/block_tile.png");
	game->img.personage_r1 = create_img(game->mlx, "./sprites/reborn/reborn_R1.png");
	game->img.personage_r2 = create_img(game->mlx, "./sprites/reborn/reborn_R2.png");
	game->img.personage_r3 = create_img(game->mlx, "./sprites/reborn/reborn_R3.png");
	game->img.personage_l1 = create_img(game->mlx, "./sprites/reborn/reborn_L1.png");
	game->img.personage_l2 = create_img(game->mlx, "./sprites/reborn/reborn_L2.png");
	game->img.personage_l3 = create_img(game->mlx, "./sprites/reborn/reborn_L3.png");
	game->img.exit = create_img(game->mlx, "./sprites/BrickHouse.png");
	game->img.collectable = create_img(game->mlx, "./sprites/collectable.png");
	game->img.enemy = create_img(game->mlx, "./sprites/ghost1.png");
	game->img.enemy2 = create_img(game->mlx, "./sprites/ghost2.png");
	game->img.enemy3 = create_img(game->mlx, "./sprites/ghost3.png");
	game->img.enemy4 = create_img(game->mlx, "./sprites/ghost4.png");
	game->img.death_msg = create_img(game->mlx, "./sprites/death_msg.png");
	game->img.win_msg = create_img(game->mlx, "./sprites/win_msg.png");
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
		}
		x++;
	}
}

void	draw_text_space(t_game *game)
{
	char	*src;

	if (game->img.text)
		mlx_delete_image(game->mlx, game->img.text);
	src = ft_itoa(game->count_mov);
	mlx_image_to_window(game->mlx, game->img.scroll, TILE, 0);
	game->img.text = mlx_put_string(game->mlx, src, 2 * 64 - 12, 14);
	free(src);
}
