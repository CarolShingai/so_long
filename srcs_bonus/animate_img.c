/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:49:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/26 17:46:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	count_loop(void *param)
{
	t_game	*game;
	int		time;

	game = (t_game *)param;
	time = mlx_get_time() * 10;
	if (game->game_status == FALSE)
	{
		disable_left(game);
		disable_right(game);
	}
	else if (game->mov == RIGHT)
	{
		animate_player_right(game, time);
		disable_left(game);
	}
	else if (game->mov == LEFT)
	{
		animate_player_left(game, time);
		disable_right(game);
	}
}

void	animate_player_right(t_game *game, int time)
{
	if (time % 9 == 0)
	{
		game->img.personage_r1->enabled = false;
		game->img.personage_r2->enabled = true;
		game->img.personage_r3->enabled = false;
	}
	else if (time % 6 == 0)
	{
		game->img.personage_r1->enabled = 0;
		game->img.personage_r2->enabled = 0;
		game->img.personage_r3->enabled = 1;
	}
	else if (time % 3 == 0)
	{
		game->img.personage_r1->enabled = 1;
		game->img.personage_r2->enabled = 0;
		game->img.personage_r3->enabled = 0;
	}
}

void	animate_player_left(t_game *game, int time)
{
	if (time % 9 == 0)
	{
		game->img.personage_l1->enabled = false;
		game->img.personage_l2->enabled = true;
		game->img.personage_l3->enabled = false;
	}
	else if (time % 6 == 0)
	{
		game->img.personage_l1->enabled = 0;
		game->img.personage_l2->enabled = 0;
		game->img.personage_l3->enabled = 1;
	}
	else if (time % 3 == 0)
	{
		game->img.personage_l1->enabled = 1;
		game->img.personage_l2->enabled = 0;
		game->img.personage_l3->enabled = 0;
	}
}

void	disable_left(t_game *game)
{
	game->img.personage_l1->enabled = 0;
	game->img.personage_l2->enabled = 0;
	game->img.personage_l3->enabled = 0;
}

void	disable_right(t_game *game)
{
	game->img.personage_r1->enabled = 0;
	game->img.personage_r2->enabled = 0;
	game->img.personage_r3->enabled = 0;
}
