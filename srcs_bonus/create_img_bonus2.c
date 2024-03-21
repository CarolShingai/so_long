/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:13:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/21 16:35:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void draw_personage(t_game *game)
{
	int x;
	int y;

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
				game->img.personage_r2->instances[0].enabled = false;
				mlx_image_to_window(game->mlx, game->img.personage_l1,
									y * TILE, x * TILE);
				game->img.personage_l1->instances[0].enabled = false;
				mlx_image_to_window(game->mlx, game->img.personage_l2,
									y * TILE, x * TILE);
				game->img.personage_l2->instances[0].enabled = false;
			}
		}
	}
}

void draw_personage_dir(t_game *game, t_moviment mov)
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
