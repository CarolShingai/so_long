/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:50:05 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/07 21:16:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_action(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *) param;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		personage_moviment_horizontal(game, game->map.personage.x, game->map.personage.y, right);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		personage_moviment_horizontal(game, game->map.personage.x, game->map.personage.y, left);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		personage_moviment_vertical(game, game->map.personage.x, game->map.personage.y, up);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		personage_moviment_vertical(game, game->map.personage.x, game->map.personage.y, down);
	else if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	personage_moviment_vertical(t_game *game, int pers_x, int pers_y, t_moviment mov)
{
	int	temp_x;
	int	temp_y;

	temp_x = pers_x;
	temp_y = pers_y;
	if ((game->map.map[pers_x + mov][pers_y] != '1') && (game->map.map[pers_x + mov][pers_y] != 'E'))
	{
		game->map.personage.x += mov;
		get_collectables(game, pers_x, pers_y);
		game->map.map[pers_x][game->map.personage.y] = 'P';
		game->img.personage->instances[0].y += TILE * mov;
		game->map.map[temp_x][temp_y] = '0';
		game->n_mov += 1;
		ft_printf("Movimentos: %d\n", game->n_mov);
	}
}

void	personage_moviment_horizontal(t_game *game, int pers_x, int pers_y, t_moviment mov)
{
	int	temp_x;
	int	temp_y;

	temp_x = pers_x;
	temp_y = pers_y;
	if ((game->map.map[pers_x][pers_y + mov] != '1') && (game->map.map[pers_x][pers_y + mov] != 'E'))
	{
		game->map.personage.y += mov;
		get_collectables(game, pers_x, pers_y);
		game->map.map[pers_x][game->map.personage.y] = 'P';
		game->img.personage->instances[0].x += TILE * mov;
		game->map.map[temp_x][temp_y] = '0';
		game->n_mov += 1;
		ft_printf("Movimentos: %d\n", game->n_mov);
	}
}

void	get_collectables(t_game *game, int pers_x, int pers_y)
{
	ft_printf("n_imgs:%d", game->img.collectable->count);
	// size_t	i;

	// i = 0;
	if (game->map.map[pers_x][pers_y] == 'C')
	{
		// while (i < game->img.collectable->count)
		// // {
		// // 	game->map.map[pers_x][pers_y] = game->img.collectable->instances[i] = 0;
		// // }
		ft_printf("Você coletou a vongole box!\n");
	}
}
