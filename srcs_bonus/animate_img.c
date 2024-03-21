/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:49:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/21 16:58:13 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void count_loop(void *param)
{
	t_game *game;
	int time;

	game = (t_game *)param;
	time = mlx_get_time() * 10;
	animate_player(game, time);
}

void animate_player(t_game *game, int time)
{
	int x;
	int y;

	x = 0;
	y = 2;
	if (game->img.personage_r1->enabled || game->img.personage_r2->enabled)
	{
		x = 1;
		y = 3;
	}
	if (time % 6 == 0)
	{
		game->img.personage_r1->enabled == 0;
		game->img.personage_r2->enabled == 1;
	}
	else if (time % 3 == 0)
	{
		game->img.personage_r1->enabled == 1;
		game->img.personage_r2->enabled == 0;
	}
	animate_movement(game);
}

void animate_movement(t_game *game)
{
	int step;

	step = 4;
}