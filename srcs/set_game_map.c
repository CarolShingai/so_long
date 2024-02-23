/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:46:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/23 02:27:15 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game_map(char **map)
{
	t_map game_map;
	
	game_map.height = find_height(map);
  game_map.width = ft_strlen(*map);
	ft_printf("altura:%d\n largura:%d", game_map.height, game_map.width);
	check_map_game(game_map, map);
}

int	find_height(char **map)
{
	int count;
	int	idx_str;

	count = 0;
	idx_str = -1;
	while(map[++idx_str])
		count++;
	return(count);
}

