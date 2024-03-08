/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:46:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/07 20:12:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_game_map(char **map, t_game *game)
{
	game->map.height = find_height(map);
	game->map.width = ft_strlen(*map);
	game->map.n_colectable = count_itens(map, 'C');
	ft_printf("collect:%d\n", game->map.n_colectable);
	set_personage(game);
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

void	set_personage(t_game *game)
{
	int	x;
	int	y;

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
	ft_printf("x:%d y:%d\n", game->map.personage.x, game->map.personage.y);
}
