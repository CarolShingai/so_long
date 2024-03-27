/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:59:40 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/26 21:22:08 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_enemies)
	{
		i = 0;
		if (game->enemy.direction == RIGHT && valid_position_enemy_right(game,
			((game->img.enemy->instances[i].y) / TILE),
			((game->img.enemy->instances[i].x) / TILE)) == TRUE)
			move_enemy_right(game, i);
		else if (game->enemy.direction == LEFT && valid_position_enemy_left(game,
			((game->img.enemy->instances[i].y + 10) / TILE),
			((game->img.enemy->instances[i].x + 10) / TILE)) == TRUE)
			move_enemy_left(game, i);
		ft_printf("%d\n", (valid_position_enemy_left(game,
		((game->img.enemy->instances[i].y + 10) / TILE),
		((game->img.enemy->instances[i].x + 10) / TILE))));
		i++;
	}
}
void	move_enemy_right(t_game *game, int i)
{
	if (valid_position_enemy_right(game,
	((game->img.enemy->instances[i].y) / TILE),
	((game->img.enemy->instances[i].x) / TILE)) == TRUE)
	{
		game->img.enemy->instances[i].x += 1;
		game->img.enemy2->instances[i].x += 1;
		game->img.enemy3->instances[i].x += 1;
		game->img.enemy4->instances[i].x += 1;
	}
	else
		game->enemy.direction = LEFT;
}

void	move_enemy_left(t_game *game, int i)
{
	if (valid_position_enemy_left(game,
	((game->img.enemy->instances[i].y + 10) / TILE),
	((game->img.enemy->instances[i].x + 10) / TILE)) == TRUE)
	{
		game->img.enemy->instances[i].x -= 1;
		game->img.enemy2->instances[i].x -= 1;
		game->img.enemy3->instances[i].x -= 1;
		game->img.enemy4->instances[i].x -= 1;
	}
	else
		game->enemy.direction = RIGHT;
}
t_bool	valid_position_enemy_right(t_game *game, int x, int y)
{
	if (game->map.map[x][y + 1] != '1' && game->map.map[x][y + 1] != 'C'
		&& game->map.map[x][y + 1] != 'E')
		return TRUE;
	return FALSE;
}

t_bool	valid_position_enemy_left(t_game *game, int x, int y)
{
	if (game->map.map[x][y - 1] != '1' && game->map.map[x][y - 1] != 'C'
		&& game->map.map[x][y - 1] != 'E')
		return TRUE;
	return FALSE;
}

void	enemy_map_position(t_game *game)
{
	int	temp;

	temp = game->map.enemy.y;
	if (game->map.map[game->map.enemy.x][game->map.enemy.y + 1] != '1'
		&& game->map.map[game->map.enemy.x][game->map.enemy.y + 1] != 'C'
		&& game->map.map[game->map.enemy.x][game->map.enemy.y + 1] != 'E')
	{
		game->map.enemy.y += 1;
		game->map.map[game->map.enemy.x][game->map.enemy.y] = 'V';
		game->map.map[game->map.enemy.x][temp] = '0';
	}
}
