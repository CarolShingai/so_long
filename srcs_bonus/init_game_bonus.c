/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:03:41 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/26 16:05:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_game(t_game *game)
{
	game->count_mov = 0;
	game->player_collectables = 0;
	game->exit_status = FALSE;
	game->game_status = TRUE;
	game->mov = RIGHT;
	setting_window(game);
	mlx_key_hook(game->mlx, &key_action, game);
	mlx_loop_hook(game->mlx, &count_loop, game);
	mlx_loop_hook(game->mlx, &count_loop_enemy, game);
	mlx_loop(game->mlx);
	ft_free_split(game->map.map);
	mlx_terminate(game->mlx);
}

void	setting_window(t_game *game)
{
	game->icon = mlx_load_png("./sprites/icon.png");
	if (!game->icon)
		ft_error(TEXTURE_ERROR);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(TILE * game->map.width, TILE * game->map.height,
			"so_long", true);
	mlx_set_icon(game->mlx, game->icon);
	insert_img(game);
	insert_img2(game);
	draw_map(game);
	draw_text_space(game);
	draw_special_tile(game);
	draw_personage(game);
	draw_personage2(game);
	draw_enemy(game);
	mlx_delete_texture(game->icon);
}
