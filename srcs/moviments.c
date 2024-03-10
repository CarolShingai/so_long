/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:50:05 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/10 18:44:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void key_action(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
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

void personage_moviment_vertical(t_game *game, int pers_x, int pers_y, t_moviment mov)
{
	int temp_x;
	int temp_y;

	temp_x = pers_x;
	temp_y = pers_y;
	if ((game->map.map[pers_x + mov][pers_y] != '1'))
	{
		if (game->map.map[pers_x + mov][pers_y] == 'C')
			get_collectables(game, pers_x + mov, pers_y);
		game->map.personage.x += mov;
		game->map.map[game->map.personage.x][pers_y] = 'P';
		game->img.personage->instances[0].y += TILE * mov;
		game->count_mov += 1;
		if ((temp_x == game->map.exit.x) && (temp_y == game->map.exit.y))
			game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
		else
			game->map.map[temp_x][temp_y] = '0';
	}
	ft_printf("Movimentos: %d\n", game->count_mov);
}

void personage_moviment_horizontal(t_game *game, int pers_x, int pers_y, t_moviment mov)
{
	int temp_x;
	int temp_y;

	temp_x = pers_x;
	temp_y = pers_y;
	if ((game->map.map[pers_x][pers_y + mov] != '1'))
	{
		if (game->map.map[pers_x][pers_y + mov] == 'C')
			get_collectables(game, pers_x, pers_y + mov);
		game->map.personage.y += mov;
		game->img.personage->instances[0].x += TILE * mov;
		game->count_mov += 1;
		game->map.map[pers_x][game->map.personage.y] = 'P';
		if ((temp_x == game->map.exit.x) && (temp_y == game->map.exit.y))
			game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
		else
			game->map.map[temp_x][temp_y] = '0';
	}
	ft_printf("Movimentos: %d\n", game->count_mov);
}

void get_collectables(t_game *game, int pers_x, int pers_y)
{
	size_t i;

	i = 0;
	while (i < game->img.collectable->count)
	{
		ft_printf("img:%d pers:%d\n", (game->img.collectable->instances[i].y + 10) / TILE, pers_x);
		if ((((game->img.collectable->instances[i].x + 10) / TILE) == pers_y) && (((game->img.collectable->instances[i].y + 10) / TILE) == pers_x) && (game->img.collectable->instances[i].enabled))
		{
			game->img.collectable->instances[i].enabled = false;
			game->player_collectables++;
			game->map.box_to_collect--;
			ft_printf("Box Coletadas:%d\n", game->player_collectables);
		}
		i++;
	}
}
