/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:03:41 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/11 17:30:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_game(t_game *game)
{
	game->count_mov = 0;
	game->player_collectables = 0;
	game->exit_state = FALSE;
	game->time = 0;
	setting_window(game);
	mlx_key_hook(game->mlx, &key_action, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
