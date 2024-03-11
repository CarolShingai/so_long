/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:46:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/10 22:41:38 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void set_game_map(char **map, t_game *game)
{
	game->map.height = find_height(map);
	game->map.width = ft_strlen(*map);
	game->map.box_to_collect = count_itens(map, 'C');
	set_personage(game);
	set_exit(game);
}

int find_height(char **map)
{
	int count;
	int idx_str;

	count = 0;
	idx_str = -1;
	while (map[++idx_str])
		count++;
	return (count);
}

void set_personage(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (game->map.map[x][y] == 'P')
			{
				game->map.personage.y = y;
				game->map.personage.x = x;
			}
			y++;
		}
		x++;
	}
}

void set_exit(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (game->map.map[x][y] == 'E')
			{
				game->map.exit.y = y;
				game->map.exit.x = x;
			}
			y++;
		}
		x++;
	}
}