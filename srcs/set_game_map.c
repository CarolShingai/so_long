/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:46:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/01 17:45:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game_map(char **map, t_map *game_map)
{
	game_map->height = find_height(map);
	game_map->width = ft_strlen(*map);
	ft_printf("altura:%d\nlargura:%d\n", game_map->height, game_map->width);
	set_personage(game_map);
}

int	find_height(char **map)
{
	int	count;
	int	idx_str;

	count = 0;
	idx_str = -1;
	while (map[++idx_str])
		count++;
	return (count);
}

void	set_personage(t_map *game_map)
{
	int	x;
	int	y;

	x = 0;
	while (game_map->map[x])
	{
		y = 0;
		while (game_map->map[x][y])
		{
			if (game_map->map[x][y] == 'P')
			{
				game_map->personage.y = y;
				game_map->personage.x = x;
			}
			y++;
		}
		x++;
	}
	ft_printf("x:%d y:%d\n", game_map->personage.x, game_map->personage.y);
}
