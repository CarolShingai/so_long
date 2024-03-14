/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moviment_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:00:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/13 19:56:34 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_bool	enemy_exist(t_game *game)
{
	if (count_itens(game->map.map, 'V') > 0)
		return (TRUE);
	return (FALSE);
}

void	e_can_move(t_game *game)
{
	int	mov_e;
	int	temp_y;

	mov_e = 0;
	temp_y = game->map.enemy.y;
	if (game->map.enemy.y +1 != '1' || game->map.enemy.y + 1 != 'E' || game->map.enemy.y + 1 != 'C')
	{
		mov_e++;
		while (game->enemy.to_move > 0)
		{
			// mlx_delete_image("")
			ft_printf("%d\n", game->map.enemy.y);
			game->map.enemy.y++;
			// game->img.enemy->enabled = false;
			game->img.enemy->instances[0].y += TILE;
			game->map.map[game->map.enemy.x][temp_y] = '0';
			game->enemy.to_move--;
		}
	}
}
