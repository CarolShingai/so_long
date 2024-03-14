/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moviment_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:00:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/14 20:04:07 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_bool	enemy_exist(t_game *game)
{
	if (count_itens(game->map.map, 'V') > 0)
		return (TRUE);
	return (FALSE);
}

// void	e_can_move(t_game *game)
// {
// 	int	mov_e;
// 	int	temp_y;

// 	mov_e = 0;
// 	temp_y = game->map.enemy.y;
// 	mlx_delete_image(game->mlx, game->img.enemy);
// 	while (game->count_enemies > 0)
// 	{
// 		game->img.enemy = create_img(game->mlx, "./sprites/mafia_L2.png");
// 		if (game->map.enemy.y +1 != '1' || game->map.enemy.y + 1 != 'E' || game->map.enemy.y + 1 != 'C')
// 		{
// 			mov_e++;
// 			game->map.enemy.y++;
// 			game->map.map[game->map.enemy.x][temp_y] = '0';
// 			game->enemy.to_move--;
// 		}
// 			mlx_image_to_window(game->mlx, game->img.enemy, game->map.enemy.x, game->map.enemy.y);
// 	}
// }
