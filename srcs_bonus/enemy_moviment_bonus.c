/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moviment_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:00:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/11 19:33:04 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_bool	enemy_exist(t_game *game)
{
	if (count_itens(game->map.map, 'V') > 0)
		return (TRUE);
	return (FALSE);
}

// void	enemy_moviment(t_game *game)
// {
// 	int	to_move;
// 	size_t	i;

// 	to_move = 3;
// 	i = 0;
// 	while (i < game->img.enemy->count)
// 	{
// 		if (enemy_exist(game) == TRUE)
// 		{
// 			if (game->img.enemy->instances[i].x + 1 != '1')
// 			{
// 				game->img.enemy->instances[i].x += 1;
// 				to_move--;
// 			}
// 			else
// 			{
// 				game->img.enemy->instances[i].x -= 1;
// 				to_move--;
// 			}
// 		}
// 		i++;
// 	}
// }
