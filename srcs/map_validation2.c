/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:52:51 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/01 18:35:32 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_itens(char **map, char item)
{
	int	count;
	int	idx_str;
	int	idx_char;

	count = 0;
	idx_str = -1;
	while (map[++idx_str])
	{
		idx_char = 0;
		while(map[idx_str][idx_char])
		{
			if (map[idx_str][idx_char] == item)
				count++;
			idx_char++;
		}
	}
	return (count);
}

int	check_flood_fill(t_map game_map)
{
	int x;
	int y;

	x = 0;
	fload_fill(game_map.map, game_map.personage.x, game_map.personage.y);
	while (game_map.map[x])
	{
		y = 0;
		ft_printf("%s\n", game_map.map[x]);
		while (game_map.map[x][y])
		{
			if (ft_strchr("PCE", game_map.map[x][y]) != NULL)
				return (FALSE);
			y++;
		}
		x++;
	}
	return (TRUE);
}

void	fload_fill(char **map, int x, int y)
{
	if (map[x][y] != '1')
	{
		map[x][y] = '1';
		fload_fill(map, x, y + 1);
		fload_fill(map, x, y - 1);
		fload_fill(map, x + 1, y);
		fload_fill(map, x - 1, y);
	}
}