/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:03:41 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/14 20:57:39 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_game(t_game *game)
{
	game->count_mov = 0;
	game->player_collectables = 0;
	game->exit_state = FALSE;
	game->enemy.direction = LEFT;
	game->enemy.to_move = 3;
	setting_window(game);
	mlx_key_hook(game->mlx, &key_action, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	setting_window(t_game *game)
{
	game->icon = mlx_load_png("./sprites/reborn_1.png");
	if (!game->icon)
		ft_error(TEXTURE_ERROR);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(TILE * game->map.width, TILE * game->map.height,
			"so_long", true);
	mlx_set_icon(game->mlx, game->icon);
	insert_img(game);
	draw_map(game);
	draw_text_space(game);
	draw_special_tile(game);
	draw_personage(game);
}
