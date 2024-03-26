/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:13:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/26 16:02:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_personage(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'P')
			{
				mlx_image_to_window(game->mlx, game->img.personage_r1,
					y * TILE, x * TILE);
				mlx_image_to_window(game->mlx, game->img.personage_r2,
					y * TILE, x * TILE);
				game->img.personage_r2->enabled = false;
				mlx_image_to_window(game->mlx, game->img.personage_l1,
					y * TILE, x * TILE);
				game->img.personage_l1->enabled = false;
				mlx_image_to_window(game->mlx, game->img.personage_l2,
					y * TILE, x * TILE);
				game->img.personage_l2->enabled = false;
			}
		}
	}
}

void	draw_personage2(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'P')
			{
				mlx_image_to_window(game->mlx, game->img.personage_r3,
					y * TILE, x * TILE);
				game->img.personage_r3->enabled = false;
				mlx_image_to_window(game->mlx, game->img.personage_l3,
					y * TILE, x * TILE);
				game->img.personage_l3->enabled = false;
			}
		}
	}
}

void	draw_enemy(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map.map[++x])
	{
		y = -1;
		while (game->map.map[x][++y])
		{
			if (game->map.map[x][y] == 'V')
			{
				mlx_image_to_window(game->mlx, game->img.enemy,
					y * TILE, x * TILE);
				mlx_image_to_window(game->mlx, game->img.enemy2,
					y * TILE, x * TILE);
				game->img.enemy2->enabled = false;
				mlx_image_to_window(game->mlx, game->img.enemy3,
					y * TILE, x * TILE);
				game->img.enemy3->enabled = false;
				mlx_image_to_window(game->mlx, game->img.enemy4,
					y * TILE, x * TILE);
				game->img.enemy4->enabled = false;
			}
		}
	}
}

void	draw_personage_dir(t_game *game, t_moviment mov)
{
	if (mov == RIGHT)
	{
		game->img.personage_r1->instances[0].enabled = true;
		game->img.personage_l1->instances[0].enabled = false;
	}
	else if (mov == LEFT)
	{
		game->img.personage_r1->instances[0].enabled = false;
		game->img.personage_l1->instances[0].enabled = true;
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
