/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:03:41 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/05 00:08:01 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * TILE, game->map.height * TILE, "so_long", true);
	if(!game->mlx)
		ft_error(SOME_ERROR);
	create_img
}
