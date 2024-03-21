/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:32:12 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/21 15:27:10 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void enable_exit(t_game *game)
{
	if (game->map.box_to_collect == 0)
	{
		game->img.exit->instances[0].enabled = true;
		ft_printf("Você coletou todas boxes!\n");
		ft_printf("A saída foi habilitada.\n");
		game->exit_status = TRUE;
	}
}

void finish_game(t_game *game)
{
	if (((game->map.personage.x == game->map.exit.x) && (game->map.personage.y == game->map.exit.y) && game->exit_status == TRUE))
	{
		mlx_close_window(game->mlx);
		ft_free_split(game->map.map);
		ft_printf("You win!\n");
	}
	else if (game->map.map[game->map.personage.x][game->map.personage.y] == 'V')
	{
		game->game_status = FALSE;
		game->img.personage_l1->enabled = false;
		game->img.personage_r1->enabled = false;
		mlx_image_to_window(game->mlx, game->img.death_msg,
							(TILE * game->map.width) / 2, (TILE * game->map.height) / 3);
	}
}
