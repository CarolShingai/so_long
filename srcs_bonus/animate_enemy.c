/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:39:29 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/26 21:23:02 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	count_loop_enemy(void *param)
{
	t_game		*game;
	static int	time;
	static int	count;

	game = (t_game *)param;
	time++;
	if (time == 8)
	{
		time = 0;
		count++;
	}
	if (count >= 4)
		count = 0;
	// move_enemy(game);
	// enemy_map_position(game);
	animate_enemy(game, count);
}

void	animate_enemy(t_game *game, int time)
{
	if (time == 3)
	{
		game->img.enemy->enabled = false;
		game->img.enemy2->enabled = false;
		game->img.enemy3->enabled = false;
		game->img.enemy4->enabled = true;
	}
	else if (time == 2)
	{
		game->img.enemy->enabled = false;
		game->img.enemy2->enabled = false;
		game->img.enemy3->enabled = true;
		game->img.enemy4->enabled = false;
	}
	else if (time == 1)
	{
		game->img.enemy->enabled = false;
		game->img.enemy2->enabled = true;
		game->img.enemy3->enabled = false;
		game->img.enemy4->enabled = false;
	}
	else if (time == 0)
		animate_enemy2(game);
}

void	animate_enemy2(t_game *game)
{
		game->img.enemy->enabled = true;
		game->img.enemy2->enabled = false;
		game->img.enemy3->enabled = false;
		game->img.enemy4->enabled = false;
}
