/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:22:23 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/21 16:38:57 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    update_img_vertical(t_game *game, t_moviment mov)
{
    game->img.personage_r1->instances[0].y += TILE * mov;
    game->img.personage_r2->instances[0].y += TILE * mov;
	game->img.personage_l1->instances[0].y += TILE * mov;
    game->img.personage_l2->instances[0].y += TILE * mov;
}

void    update_img_horizontal(t_game *game, t_moviment mov)
{
    game->img.personage_r1->instances[0].x += TILE * mov;
    game->img.personage_r2->instances[0].x += TILE * mov;
	game->img.personage_l1->instances[0].x += TILE * mov;
    game->img.personage_l2->instances[0].x += TILE * mov;
}